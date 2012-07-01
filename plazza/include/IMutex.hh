//
// IMutex.hh for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Sat Apr  9 10:16:53 2011 vincent hugues
// Last update Thu Apr 14 18:32:28 2011 vincent hugues
//

#ifndef		IMUTEX_HH_
# define	IMUTEX_HH_

class		IMutex
{
public:
  virtual ~IMutex(void) {}

  virtual pthread_mutex_t*	getMutex(void) = 0;
  virtual void			lock(void) = 0;
  virtual void			unlock(void) = 0;
  virtual void			trylock(void) = 0;
};

#endif		/* !IMUTEX_HH_ */
