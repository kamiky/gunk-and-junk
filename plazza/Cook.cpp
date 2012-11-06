//
// Cook.cpp
// Rock n' roll never dies
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Sat Apr  9 10:03:49 2011 patrick rabier
// Started on  Sat Apr  9 10:03:49 2011 patrick rabier
//

#include <unistd.h>
#include <iostream>
#include "Cook.hh"

typedef std::map<Ingredients, unsigned int> Reserve;

Cook::Cook(Kitchen *k, float mul) : _kitchen(k), _prepMul(mul)
{
  _is_alive=true;
  _currentOrder = 0;
  for (int i = 1; i <= Amour; i *= 2)
    _ingList.push_back(static_cast<Ingredients>(i));
}

Cook::~Cook()
{
}

void Cook::mix(int recipe)
{
  std::list<Ingredients>::iterator	it = _ingList.begin();
  std::list<Ingredients>::iterator	end = _ingList.end();

  while (it != end)
    {
      if ((*it) & recipe)
	_kitchen->getIngredient(*it);
      ++it;
    }
}

void Cook::kill()
{
  _is_alive = false;
}

void Cook::prepare()
{
  int			recipe;
  float			time;
  char			size = 0;
  char		       	type = 0;

  if (_currentOrder == 0)
    return ;
  _kitchen->resetTick();
  size |= _currentOrder;
  _currentOrder >>= 8;
  type |= _currentOrder;
  time = Recipe::getCookingTime(static_cast<TypePizza>(type)) * _prepMul;
  recipe = Recipe::getRecipe(static_cast<TypePizza>(type));
  mix(recipe);
  while (time > 0)
    {
      _kitchen->resetTick();
      usleep(((time > 1) ? 1 : time) * 1000000);
      time--;
    }
  _currentOrder = 0;
  _kitchen->finishedOrder(static_cast<TypePizza>(type));
}

void	Cook::getOrder()
{
  _currentOrder = _kitchen->popOrder();
}

void	Cook::startCooking()
{
  while (_is_alive)
    {
      getOrder();
      prepare();
    }
}
