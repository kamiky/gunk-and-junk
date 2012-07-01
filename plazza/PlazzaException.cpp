//
// PlazzaException.cpp for plazza in /home/hugues_v//epitech/cpp/plazza/plazza-2014-hugues_v/trunk
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Thu Apr 14 15:51:20 2011 vincent hugues
// Last update Thu Apr 14 18:21:11 2011 vincent hugues
//

#include "PlazzaException.hh"

PlazzaException::PlazzaException(ePlazzaExceptionType const excp)
  : _exception(excp)
{}

PlazzaException::~PlazzaException() throw()
{}

const char* PlazzaException::what() const throw()
{
  switch (_exception) {
  case PTHREAD_CREATE:
    return "pthread_create() error";
  case PTHREAD_JOIN:
    return "pthread_join() error";
  case PTHREAD_MUTEX_INIT:
    return "pthread_mutex_init() error";
  case PTHREAD_MUTEX_DESTROY:
    return "pthread_mutex_destroy() error";
  case PTHREAD_MUTEX_LOCK:
    return "pthread_mutex_lock() error";
  case PTHREAD_MUTEX_UNLOCK:
    return "pthread_mutex_unlock() error";
  case PTHREAD_MUTEX_TRYLOCK:
    return "pthread_mutex_trylock() error";
  case PTHREAD_COND_INIT:
    return "pthread_cond_init() error";
  case PTHREAD_COND_DESTROY:
    return "pthread_cond_destroy() error";
  case PTHREAD_COND_WAIT:
    return "pthread_cond_wait() error";
  case PTHREAD_COND_SIGNAL:
    return "pthread_cond_signal() error";
  case PTHREAD_COND_BROADCAST:
    return "pthread_cond_broadcast() error";
  default:
    return "Unknown error";
  }
}
