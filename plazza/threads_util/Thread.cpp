//
// Thread.cpp for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Sat Apr  9 10:26:06 2011 vincent hugues
// Last update Thu Apr 14 18:35:23 2011 vincent hugues
//

#include <pthread.h>
#include "Thread.hh"
#include "PlazzaException.hh"

Thread::Thread(void* (*fct)(void*), void* p)
  : _routine(fct), _params(p), _status(THR_WAITING)
{}

Thread::~Thread()
{}

Thread::Status	Thread::getStatus(void)
{
  return _status;
}

void	Thread::start(void)
{
  if (pthread_create(&_thr, NULL, _routine, _params) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_CREATE);
  _status = THR_ALIVE;
}

void	Thread::join(void** retValue)
{
  if (getStatus() != Thread::THR_ALIVE)
    return;
  if (pthread_join(_thr, retValue))
    throw PlazzaException(PlazzaException::PTHREAD_JOIN);
  _status = THR_DEAD;
}
