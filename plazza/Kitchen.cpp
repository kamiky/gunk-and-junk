//
// Kitchen.cpp
// You touch my tralala !
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Sun Apr 10 11:00:53 2011 patrick rabier
// Started on  Sun Apr 10 11:00:53 2011 patrick rabier
//

#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include "Kitchen.hh"

//////// TRAMPOLINES ////////

void *  start_reserve(void * p)
{
  reinterpret_cast<Kitchen *>(p)->reserveHandle();
  return NULL;
}

void *	start_cooks(void * p)
{
  reinterpret_cast<Cook *>(p)->startCooking();
  return NULL;
}

/////// MISC ///////

void	Kitchen::debug(const char *s)
{
  mcout.lock();
  std::cout << s << std::endl;
  mcout.unlock();
}

///// CONSTRUCTION/DESTRUCTION /////

Kitchen::Kitchen(int staffCount, float refreshRes, float pizzaMul, Waiter * wait)
  : _condReserve(_reserveLock), _condNewOrder(_orderLock),
    _orders(), _threadRes(start_reserve, this), _waiter(wait),
    _resRefreshRate(refreshRes)
{
  // info
  _nbCooks = staffCount;
  for (int i = 0; i < NB_PIZZA; _infos.ready[i++] = 0);
  _infos.waiting = 0;
  _infos.inPrep = 0;
  _infos.destroyed = false;
  // content
  for (unsigned int i = 0; i < _nbCooks; ++i) {
    _staff.push_back(Cook(this, pizzaMul));
    _threads.push_back(Thread(start_cooks, &(_staff.back())));
  }
  for (int ing = 1; ing <= Amour; ing *= 2)
    _reserve[static_cast<Ingredients>(ing)] = 5;
  if (gettimeofday(&_lastTick, NULL))
    std::cerr << "gettimeofday fail.\n";
}

Kitchen::~Kitchen()
{
}

///// INFOS /////

void	Kitchen::finishedOrder(TypePizza p)
{
  int	i = 0;

  _infos.inPrep--;
  for (int mul = 1; mul != p; mul *= 2, ++i);
  _infos.ready[i]++;
}

///// FUNCTIONS /////

void	Kitchen::resetTick()
{
  _timeLock.lock();
  if (gettimeofday(&_lastTick, NULL))
    std::cerr << "gettimeofday fail.\n";
  _timeLock.unlock();
}

/*
 * Assigns the recieved order to a chef !
 */
void	Kitchen::pushOrder(unsigned short o)
{
  _orderLock.lock();
  _orders.push(o);
  _condNewOrder.signal();
  _infos.waiting++;
  _orderLock.unlock();
}

unsigned short	Kitchen::popOrder()
{
  unsigned short elem = 0;

  _orderLock.lock();
  if (_orders.empty())
    {
      _condNewOrder.wait();
      if (_infos.destroyed)
	{
	  _orderLock.unlock();
	  return 0;
	}
    }
  elem = _orders.front();
  _orders.pop();
  _infos.inPrep++;
  _infos.waiting--;
  _orderLock.unlock();
  return elem;
}

void	Kitchen::getIngredient(Ingredients i)
{
  _reserveLock.lock();
  while (_reserve[i] <= 0) {
    _condReserve.wait();
  }
  _reserve[i]--;
  _reserveLock.unlock();
}

void	Kitchen::demolish()
{
  std::list<Cook>::iterator	itCook = _staff.begin();
  std::list<Cook>::iterator	lastCook = _staff.end();
  std::list<Thread>::iterator	itThread = _threads.begin();
  std::list<Thread>::iterator	lastThread = _threads.end();

  while (itCook != lastCook)
    {
      (*itCook).kill();
      ++itCook;
    }
  _infos.destroyed = true;
  _threadRes.join(NULL);
  _condNewOrder.broadcast();
  while (itThread != lastThread)
    {
      (*itThread).join(NULL);
      ++itThread;
    }
  _waiter->take<report>(_infos);
}

void	Kitchen::communicate()
{
  struct timeval time;
  time_t	 lastSec = 0;

  if (gettimeofday(&time, NULL))
    std::cerr << "gettimeofday fail.\n";
  while (time.tv_sec - _lastTick.tv_sec < 5)
    {
      if (lastSec == 0 || time.tv_sec - lastSec > 0)
	{
	  _waiter->take<report>(_infos);
	  lastSec = time.tv_sec;
	}
      if (_waiter->checkDelivery())
	{
	  pushOrder(_waiter->deliver<ushort>());
	  _waiter->take<report>(_infos);
	  _timeLock.lock();
	  _lastTick = time;
	  _timeLock.unlock();
	}
      if (gettimeofday(&time, NULL))
	std::cerr << "gettimeofday fail.\n";
    }
  demolish();
}

void	Kitchen::reserveHandle()
{
  Reserve::iterator	it;
  Reserve::iterator	end = _reserve.end();

  while (!_infos.destroyed)
    {
      usleep(_resRefreshRate * 1000);
      it = _reserve.begin();
      _reserveLock.lock();
      while (it != end)
	{
	  (*it).second++;
	  ++it;
	}
      _condReserve.broadcast();
      _reserveLock.unlock();
    }
  _condReserve.broadcast();
}

void	Kitchen::run()
{
  // Start Cooks and PARRTAY
  std::list<Thread>::iterator it = _threads.begin();
  std::list<Thread>::iterator end = _threads.end();

  while (it != end)
    {
      (*it).start();
      ++it;
    }

  // Reserve
  _threadRes.start();
  // handle IO
  communicate();
}
