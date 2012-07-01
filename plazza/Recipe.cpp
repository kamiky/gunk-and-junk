//
// Recipe.cpp
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Wed Apr  6 18:41:33 2011 patrick rabier
// Started on  Wed Apr  6 18:41:33 2011 patrick rabier
//

#include <iostream>
#include "Recipe.hh"

CookBook Recipe::book = CookBook();
CookBook Recipe::time = CookBook();

void		Recipe::init()
{
  book[Margarita] = Pate | Tomate | Gruyere;
  book[Regina] = Pate | Tomate | Gruyere | Jambon | Champignon;
  book[Americaine] = Pate | Tomate | Gruyere | Steak;
  book[Fantasia] = Pate | Tomate | Chevre | Aubergine | Amour;

  // --> sec
  time[Margarita] = 1;
  time[Regina] = 2;
  time[Americaine] = 2;
  time[Fantasia] = 4;
}

int		Recipe::getRecipe(TypePizza t)
{
  return (book[t]);
}

int		Recipe::getCookingTime(TypePizza t)
{
  return (time[t]);
}
