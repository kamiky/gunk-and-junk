//
// IThread.hh for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
//
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
//
// Started on  Sat Apr  9 10:17:59 2011 vincent hugues
// Last update Thu Apr 14 18:33:30 2011 vincent hugues
//

#ifndef		ITHREAD_HH_
# define	ITHREAD_HH_

class		IThread
{
public:
  enum		Status
    {
      THR_WAITING,
      THR_ALIVE,
      THR_DEAD
    };

  virtual ~IThread(void) {}

  virtual Status	getStatus(void) = 0;
  virtual void		start(void) = 0;
  virtual void		join(void** retValue) = 0;
};

#endif		/* !ITHREAD_HH_ */
