//
// Mutex.cpp for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Sat Apr  9 10:33:23 2011 vincent hugues
// Last update Thu Apr 14 18:31:40 2011 vincent hugues
//

#include <pthread.h>
#include <iostream>
#include "Mutex.hh"
#include "PlazzaException.hh"

Mutex::Mutex(const pthread_mutexattr_t* attr)
{
  if (pthread_mutex_init(&_mutex, attr) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_MUTEX_INIT);
}

Mutex::~Mutex(void)
{
  if (pthread_mutex_destroy(&_mutex) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_MUTEX_DESTROY);
}

pthread_mutex_t*	Mutex::getMutex(void)
{
  return &_mutex;
}

void	Mutex::lock(void)
{
  if (pthread_mutex_lock(&_mutex) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_MUTEX_LOCK);
}

void	Mutex::unlock(void)
{
  if (pthread_mutex_unlock(&_mutex) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_MUTEX_UNLOCK);
}

void	Mutex::trylock(void)
{
  if (pthread_mutex_trylock(&_mutex) != 0)
    throw PlazzaException(PlazzaException::PTHREAD_MUTEX_TRYLOCK);
}
