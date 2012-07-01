//
// Mutex.hh for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Sat Apr  9 10:17:20 2011 vincent hugues
// Last update Thu Apr 14 18:32:07 2011 vincent hugues
//

#ifndef		MUTEX_HH_
# define	MUTEX_HH_

# include	"IMutex.hh"

class		Mutex: public IMutex
{
public:
  Mutex(const pthread_mutexattr_t* attr = NULL);
  ~Mutex(void);

  virtual pthread_mutex_t*	getMutex();
  virtual void			lock(void);
  virtual void			unlock(void);
  virtual void			trylock(void);

private:
  Mutex&	operator=(const Mutex&);
  Mutex(const Mutex&);

protected:
  pthread_mutex_t		_mutex;
};

#endif		/* !MUTEX_HH_ */
