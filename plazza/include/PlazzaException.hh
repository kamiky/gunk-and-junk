//
// PlazzaException.hh for plazza in /home/hugues_v//epitech/cpp/plazza/plazza-2014-hugues_v/trunk/threads_util
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Thu Apr 14 15:54:26 2011 vincent hugues
// Last update Thu Apr 14 18:18:50 2011 vincent hugues
//

#ifndef		THREXCEPTION_HH_
# define	THREXCEPTION_HH_

# include	<exception>

class		PlazzaException: public std::exception
{
public:
  enum		ePlazzaExceptionType
    {
      PTHREAD_CREATE,
      PTHREAD_JOIN,
      PTHREAD_MUTEX_INIT,
      PTHREAD_MUTEX_DESTROY,
      PTHREAD_MUTEX_LOCK,
      PTHREAD_MUTEX_UNLOCK,
      PTHREAD_MUTEX_TRYLOCK,
      PTHREAD_COND_INIT,
      PTHREAD_COND_DESTROY,
      PTHREAD_COND_WAIT,
      PTHREAD_COND_SIGNAL,
      PTHREAD_COND_BROADCAST
    };

  PlazzaException(ePlazzaExceptionType const excp);
  ~PlazzaException() throw();
  virtual const char* what() const throw();

protected:
  ePlazzaExceptionType const	_exception;
};

#endif		/* !THREXCEPTION_HH_ */
