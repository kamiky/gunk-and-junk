//
// Menu.hh
// Gotta reach for the top !
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Thu Apr  7 09:09:04 2011 patrick rabier
// Last update Fri Apr 15 13:52:02 2011 Patrick Rabier
//

#ifndef   	MENU_HH_
# define   	MENU_HH_

#include <string>
#include <queue>
#include <map>
#include "common.hh"

typedef  std::queue<unsigned short> Order;

class Menu
{
private:
  Order _order;
  std::map<std::string, TypePizza> _types;
  std::map<std::string, TaillePizza> _sizes;

private:
  bool		setType(std::string &, unsigned short *);
  bool		setSize(std::string &, unsigned short *);
  void		addPizza(std::string &, Order &);
  Order		parse(std::string &);

private:
  /* Coplien */
  Menu(const Menu &) {};
  void	operator=(const Menu &) {};

public:
  Menu();
  ~Menu();
  Order	getOrder();
  Order	getOrder(std::string &);
};

#endif	    /* !MENU_HH_ */
