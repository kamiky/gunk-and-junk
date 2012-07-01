//
// Reception.cpp for plazza in /home/gatty_s//projets/C++/plazza-2014-hugues_v/trunk
// 
// Made by sebastien gatty
// Login   <gatty_s@epitech.net>
// 
// Started on  Thu Apr 14 14:31:57 2011 sebastien gatty
// Last update Fri Apr 15 15:18:41 2011 sebastien gatty
//

#include <iostream>
#include <unistd.h>
#include <list>
#include <string>
#include <signal.h>
#include <sys/wait.h>
#include "Menu.hh"
#include "Kitchen.hh"
#include "Recipe.hh"
#include "Reception.hh"
#include "Waiter.hh"
#include "Showcase.hh"

void sighdler(int signum)
{
  int status = 0;

  (void)signum;
  wait(&status);
}

Reception::Reception()
  : _mul(0.0), _nbCook(0), _refresh(0), _lastid(0),
    _order(), _staff(), _reports()
{
  Recipe::init();
  _showcase.init();
}

Reception::~Reception()
{
}

itstaff Reception::addKitchen()
{
  int pid;
  Waiter * waiter;
  report rep;

  waiter = new Waiter(_lastid++);
  _staff.push_back(waiter);
  for (int i = 0; i < NB_PIZZA; rep.ready[i++] = 0);
  rep.waiting = 0;
  rep.inPrep = 0;
  _reports.push_back(rep);
  if ((pid = fork()))
    {
      if (pid == -1)
	throw 42;
      waiter->from();
    }
  else
    {
      Kitchen kitchen(_nbCook, _refresh, _mul, waiter);

      waiter->to();
      kitchen.run();
      exit(0);
    }
  return (--(_staff.end()));
}

itstaff Reception::getReport(itreports * theitr)
{
  itstaff idx, it;
  itreports itr;
  int	    nbWait = -1;

  for (it = _staff.begin(), itr = _reports.begin();
       it != _staff.end(); ++it, ++itr)
    {
      if (!((*itr).destroyed) && (*it)->checkDelivery())
	(*itr) = (*it)->deliver<report>();
      if (((*itr).destroyed))
	{
	  delete (*it);
	  it = _staff.erase(it);
	  _oldReports.push_back(*itr);
	  itr = _reports.erase(itr);
	}
    }
  idx = _staff.end();
  for (it = _staff.begin(), itr = _reports.begin();
       it != _staff.end(); ++it, ++itr)
    {
      if (idx == _staff.end()
	  && (*itr).waiting + (*itr).inPrep < 2 * _nbCook
	  && ((*itr).waiting < nbWait || nbWait == -1))
	{
	  idx = it;
	  *theitr = itr;
	  nbWait = (*itr).waiting;
	}
    }
  return (idx);
}

void Reception::clean()
{
  for (itstaff it = _staff.begin(); it != _staff.end(); ++it)
    delete *it;
}

void Reception::run(float const mul, int const nbCook, int const refresh)
{
  events      event;
  itstaff     it;
  itreports   itr;
  Menu	      menu;
  Order	      newOrder;
  std::string command = "";

  signal(SIGCHLD, &sighdler);
  _mul = mul;
  _nbCook = nbCook;
  _refresh = refresh;
  while (event != QUIT)
    {
      it = this->getReport(&itr);
      event = _showcase.keyHndlr(command);
      if (event == ORDER)
	newOrder = menu.getOrder(command);
      while (!newOrder.empty())
	{
	  _order.push(newOrder.front());
	  newOrder.pop();
	}
      if (!_order.empty())
	{
	  if (it == _staff.end())
	    it = addKitchen();
	  (*it)->take<ushort>(_order.front());
	  while ((*it)->checkDelivery())
	    (*itr) = (*it)->deliver<report>();
	  _order.pop();
	}
      _showcase.display(_reports, _oldReports);
    }
  clean();
}
