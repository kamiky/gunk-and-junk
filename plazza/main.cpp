//
// main.cpp for plazza in /home/gatty_s//projets/C++/plazza-2014-hugues_v/trunk
//
// Made by sebastien gatty
// Login   <gatty_s@epitech.net>
//
// Started on  Thu Apr 14 16:53:26 2011 sebastien gatty
// Last update Fri Apr 15 08:03:45 2011 sebastien gatty
//

#include <iostream>
#include <sstream>
#include "Reception.hh"

std::string		utos(ushort u)
{
    std::stringstream	sstr;

    sstr << u;
    return (sstr.str());
}

int main(int ac, char ** av)
{
  Reception recep;
  std::stringstream sstr;
  float		mul;
  int		refresh, cook;

  if (ac != 4)
    {
      std::cerr << "usage : ./plazza multiplier nbCook refreshRate\n";
      return (1);
    }
  sstr << av[1];
  sstr >> mul;
  sstr.clear();
  sstr.str() = "";
  sstr << av[2];
  sstr >> cook;
  sstr.clear();
  sstr.str() = "";
  sstr << av[3];
  sstr >> refresh;
  recep.run(mul, cook, refresh);
  return (0);
}
