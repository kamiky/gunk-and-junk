//
// Kitchen.hh
// Hell's kitchen !
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Sun Apr 10 11:00:53 2011 patrick rabier
// Last update Thu Apr 14 15:50:10 2011 Patrick Rabier
//

#ifndef   	KITCHEN_HH_
# define   	KITCHEN_HH_

#include <map>
#include <list>
#include <queue>
#include <sys/time.h>
#include "common.hh"
#include "Mutex.hh"
#include "Thread.hh"
#include "Cook.hh"
#include "CondVar.hh"
#include "Waiter.hh"

typedef std::map<Ingredients, unsigned int> Reserve;

/*
 *@PARAM _pizzaLock mutex sur l'assignation de pizzas
 *@PARAM _reserveLock mutex, controle l'acces a la reserve
 *
 */
class Cook;
class Kitchen
{
private :
  // Bodyguard
  Mutex			_orderLock;
  Mutex			_reserveLock;
  CondVar		_condReserve;
  CondVar		_condNewOrder;

  Mutex			_timeLock;

  // COUT
  Mutex			mcout;

  // Content
  std::list<Cook>	_staff;
  std::list<Thread>	_threads;
  std::queue<unsigned short> _orders;

  // Reserve
  Reserve		_reserve;
  Thread		_threadRes;

  // Communication
  Waiter	      * _waiter;

  // Kitchen info
  unsigned int		_nbCooks;
  float			_resRefreshRate;
  report		_infos;


  // TIME
  struct timeval        _lastTick;

public :
  Kitchen(int, float, float, Waiter *);
  ~Kitchen();
  // Main function
  void	run();
  // Main threads
  void	communicate();
  void	reserveHandle();
  // Preparation and orders
  void	finishedOrder(TypePizza);
  void	pushOrder(unsigned short);
  unsigned short popOrder();
  void	getIngredient(Ingredients);
  // Exit
  void	demolish();
  // Time handler
  void	resetTick();
  // Write thread safe
  void	debug(const char*);
};

#endif	    /* !KITCHEN_HH_ */
