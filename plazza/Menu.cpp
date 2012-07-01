//
// Menu.cpp
// Keep your ammo cool and your bacon hot !
//
// Made by patrick rabier
// Login   <rabier_p@epitech.net>
//
// Started on  Thu Apr  7 09:14:19 2011 patrick rabier
// Started on  Thu Apr  7 09:14:19 2011 patrick rabier
//

#include <sstream>
#include <iostream>
#include "Menu.hh"

Menu::Menu() {
  _types["regina"] = Regina;
  _types["margarita"] = Margarita;
  _types["americaine"] = Americaine;
  _types["fantasia"] = Fantasia;

  _sizes["S"] = S;
  _sizes["M"] = M;
  _sizes["L"] = L;
  _sizes["XL"] = XL;
  _sizes["XXL"] = XXL;
}

Menu::~Menu() {
}

bool		Menu::setType(std::string & t, unsigned short *ord)
{
  for (int i = 0; t[i]; ++i)
    t[i] = std::tolower(t[i]);
  if (_types.find(t) != _types.end())
    (*ord) |= _types[t];
  else
    return false;
  return true;
}

bool		Menu::setSize(std::string & s, unsigned short *ord)
{
  for (int i = 0; s[i]; ++i)
    s[i] = std::toupper(s[i]);
  if (_sizes.find(s) != _sizes.end())
    (*ord) |= _sizes[s];
  else
    return false;
  return true;
}

void		Menu::addPizza(std::string &s, Order & order)
{
  std::stringstream	ss(s);
  std::string		tmp;
  unsigned short	cur_ord;
  int			count;

  cur_ord = 0;
  // set order short
  ss >> tmp;
  if (!setType(tmp, &cur_ord))
    return ;
  cur_ord <<= 8;
  ss >> tmp;
  if (!setSize(tmp, &cur_ord))
    return ;

  // add to queue
  ss >> count;
  if (count <= 0)
    return ;
  for (int i = 0; i < count; ++i)
    order.push(cur_ord);
}

Order		Menu::parse(std::string &s)
{
  Order		order;
  int		last;
  size_t 	cur;
  std::string	pizza;

  last  = 0;
  cur = 0;
  while ((cur = s.find(';', last)) != std::string::npos)
    {
      pizza.clear();
      pizza = s.substr(last, cur - last);
      addPizza(pizza, order);
      last = cur + 1;
    }
  return (order);
}

Order	Menu::getOrder()
{
  std::string s;

  std::getline(std::cin, s, '\n');
  for (int i = 0; s[i]; ++i)
    if (s[i] == 'x' && isdigit(s[i+1]))
      s[i] = ' ';
  s += ";";
  return parse(s);
}

Order	Menu::getOrder(std::string &s)
{
  for (int i = 0; s[i]; ++i)
    if (s[i] == 'x' && isdigit(s[i+1]))
      s[i] = ' ';
  s += ";";
  return parse(s);
}
