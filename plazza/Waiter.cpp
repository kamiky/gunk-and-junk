//
// Waiter.cpp for plazza in /home/gatty_s//projets/C++/plazza-2014-hugues_v/trunk
// 
// Made by sebastien gatty
// Login   <gatty_s@epitech.net >
// 
// Started on  Thu Apr  7 08:43:34 2011 sebastien gatty
// Last update Fri Apr 15 14:37:16 2011 sebastien gatty
//

#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Waiter.hh"
#include "common.hh"

Waiter::Waiter(int const id)
{
  std::stringstream sstr;
  std::string  str;

  sstr << id;
  sstr >> str;
  this->_stoc = "stoc" + str + ".fifo";
  mkfifo(this->_stoc.c_str(), 0644);
  sstr.str() = "";
  sstr << id;
  sstr >> str;
  this->_ctos = "ctos" + str + ".fifo";
  mkfifo(this->_ctos.c_str(), 0644);
}

Waiter::~Waiter()
{
  close(this->_in);
  close(this->_out);
  unlink(this->_stoc.c_str());
  unlink(this->_ctos.c_str());
}

void Waiter::from()
{
  if ((this->_in = open(this->_ctos.c_str(), O_RDONLY)) == -1)
    std::cerr << "from: unable to open " << this->_ctos << std::endl;
  if ((this->_out = open(this->_stoc.c_str(), O_WRONLY)) == -1)
    std::cerr << "from: unable to open " << this->_stoc << std::endl;
}

void Waiter::to()
{
  if ((this->_out = open(this->_ctos.c_str(), O_WRONLY)) == -1)
    std::cerr << "to: unable to open " << this->_stoc << std::endl;
  if ((this->_in = open(this->_stoc.c_str(), O_RDONLY)) == -1)
    std::cerr << "to: unable to open " << this->_ctos << std::endl;
}

bool Waiter::checkDelivery() const
{
  fd_set         setrd;
  struct timeval time;

  FD_ZERO(&setrd);
  FD_SET(this->_in, &setrd);
  time.tv_sec = 0;
  time.tv_usec = 0;
  select(this->_in + 1, &setrd, NULL, NULL, &time);
  return (FD_ISSET(this->_in, &setrd));
}

template <typename T>
void Waiter::take(T const & value) const
{
  fd_set         setwr;
  struct timeval time;

  time.tv_sec = 0;
  time.tv_usec = 5;
  do
    {
      FD_ZERO(&setwr);
      FD_SET(this->_out, &setwr);
      select(this->_out + 1, NULL, &setwr, NULL, &time);
    }
  while (!FD_ISSET(this->_out, &setwr));
  if (write(this->_out, &value, sizeof(T)) == -1)
    std::cerr << "Write fail.\n";
}

template <typename T>
T Waiter::deliver() const
{
  T value;

  if (read(this->_in, &value, sizeof(T)) == -1)
    std::cerr << "Read fail.\n";
  return (value);
}

template void Waiter::take<ushort>(ushort const &) const;
template ushort Waiter::deliver<ushort>() const;
template void Waiter::take<report>(report const &) const;
template report Waiter::deliver<report>() const;
