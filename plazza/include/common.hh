//
// common.hh
// Save me some sugar !
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Wed Apr  6 10:04:17 2011 patrick rabier
// Last update Thu Apr 14 18:20:41 2011 sebastien gatty
//

#ifndef   	COMMON_HH_
# define   	COMMON_HH_

#include <list>

typedef unsigned short ushort;

enum Ingredients {
  Pate = 1,
  Tomate = 2,
  Gruyere = 4,
  Jambon = 8,
  Champignon = 16,
  Steak = 32,
  Aubergine = 64,
  Chevre = 128,
  Amour = 256
};

#define NB_PIZZA 4

enum TypePizza {
  Regina = 1,
  Margarita = 2,
  Americaine = 4,
  Fantasia = 8
};

enum TaillePizza {
  S = 1,
  M = 2,
  L = 4,
  XL = 8,
  XXL = 16
};

enum events {
  NONE,
  ORDER,
  QUIT
};

struct report
{
  ushort ready[NB_PIZZA];
  ushort waiting;
  ushort inPrep;
  bool	 destroyed;
};

typedef std::list<report>   reports;
typedef std::list<report>::iterator itreports;
typedef std::list<report>::const_iterator constitreports;

std::string	utos(ushort u);

#endif	    /* !COMMON_HH_ */
