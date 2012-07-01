//
// Reception.cpp for plazza in /home/gatty_s//projets/C++/plazza-2014-hugues_v/trunk
// 
// Made by sebastien gatty
// Login   <gatty_s@epitech.net>
// 
// Started on  Thu Apr 14 14:14:57 2011 sebastien gatty
// Last update Fri Apr 15 12:10:50 2011 sebastien gatty
//

#pragma once

#include <list>
#include "Waiter.hh"
#include "Showcase.hh"

typedef std::list<Waiter*>  staff;
typedef std::list<Waiter*>::iterator itstaff;

class Reception
{
public:
  Reception();
  ~Reception();
  void run(float const, int const, int const);

private:
  itstaff  addKitchen();
  itstaff  getReport(itreports*);
  void     clean();
  

private:
  float	   _mul;
  int	   _nbCook;
  int	   _refresh;
  int	   _lastid;
  Order	   _order;
  staff	   _staff;
  reports  _reports;
  reports  _oldReports;
  Showcase _showcase;
};
