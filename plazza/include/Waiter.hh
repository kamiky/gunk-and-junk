//
// Pipe.hh for plazza in /home/gatty_s//projets/C++/plazza-2014-hugues_v/trunk
// 
// Made by sebastien gatty
// Login   <gatty_s@epitech.net>
// 
// Started on  Fri Apr  8 09:12:23 2011 sebastien gatty
// Last update Wed Apr 13 10:40:15 2011 sebastien gatty
//

#pragma once

#include <string>
#include "common.hh"

class Waiter
{
public:
  Waiter(int const);
  ~Waiter();
  void from();
  void to();
  bool checkDelivery() const;
  template <typename T> void take(T const &) const;
  template <typename T> T deliver() const;

private:
  std::string  _ctos;
  std::string  _stoc;
  int	       _in;
  int	       _out;
};
