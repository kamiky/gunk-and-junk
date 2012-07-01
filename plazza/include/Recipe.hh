//
// Recipe.hh
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Wed Apr  6 18:18:08 2011 patrick rabier
// Last update Thu Apr 14 16:05:46 2011 Patrick Rabier
//

#ifndef   	RECIPE_HH_
# define   	RECIPE_HH_

#include <map>
#include "common.hh"

typedef std::map<TypePizza, int> CookBook;

class Recipe
{
private:
  static CookBook  book;
  static CookBook  time;
public:
  static int	getRecipe(TypePizza);
  static int	getCookingTime(TypePizza);
  static void	init();
};

#endif	    /* !RECIPE_HH_ */
