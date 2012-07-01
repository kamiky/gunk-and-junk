//
// Thread.hh for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
//
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
//
// Started on  Sat Apr  9 10:18:26 2011 vincent hugues
// Last update Thu Apr 14 18:33:47 2011 vincent hugues
//

#ifndef		THREAD_HH_
# define	THREAD_HH_

# include	"IThread.hh"

class		Thread: public IThread
{
public:
  Thread(void* (*fct)(void*), void* p);
  ~Thread(void);

  virtual Status	getStatus(void);
  virtual void		start(void);
  virtual void		join(void** retValue);

protected:
  void*		(*_routine)(void*);
  void*		_params;
  Status	_status;
  pthread_t	_thr;
};

#endif		/* !THREAD_HH_ */
