//
// Cook.hh
// Le baguette !
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Sat Apr  9 09:53:20 2011 patrick rabier
// Last update Thu Apr 14 15:38:27 2011 Patrick Rabier
//

#ifndef   	COOK_HH_
# define   	COOK_HH_

#include <list>
#include <string>
#include <pthread.h>
#include "common.hh"
#include "Kitchen.hh"
#include "Recipe.hh"

class Kitchen;
class Cook
{
private :
  std::string		_name;
  std::list<Ingredients>	_ingList;
  Kitchen		*_kitchen;
  unsigned short	_currentOrder;
  float			_prepMul;
  bool			_is_alive;

private :
  void	getOrder();
  void	mix(int recipe);
  void	prepare();

private :
  /* Coplien */
  void operator=(const Cook&) {};
  Cook() {};

public:
  Cook(Kitchen *, float);
  ~Cook();
  void	startCooking();
  void	kill();
};

#endif	    /* !COOK_HH_ */
