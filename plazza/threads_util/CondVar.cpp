//
// CondVar.cpp for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Sat Apr  9 19:10:15 2011 vincent hugues
// Last update Thu Apr 14 18:21:44 2011 vincent hugues
//

#include <pthread.h>
#include "CondVar.hh"
#include "PlazzaException.hh"

CondVar::CondVar(IMutex& m)
  : _mutex(m)
{
  if (pthread_cond_init(&_cond, NULL) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_COND_INIT);
}

CondVar::~CondVar(void)
{
  if (pthread_cond_destroy(&_cond) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_COND_DESTROY);
}

void	CondVar::wait(void)
{
  if (pthread_cond_wait(&_cond, _mutex.getMutex()) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_COND_WAIT);
}

void	CondVar::signal(void)
{
  if (pthread_cond_signal(&_cond) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_COND_SIGNAL);
}

void	CondVar::broadcast(void)
{
  if (pthread_cond_broadcast(&_cond) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_COND_BROADCAST);
}
