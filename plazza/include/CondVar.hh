//
// CondVar.hh for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
//
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
//
// Started on  Sat Apr  9 16:38:25 2011 vincent hugues
// Last update Thu Apr 14 18:33:18 2011 vincent hugues
//

#ifndef		CONDVAR_HH_
# define	CONDVAR_HH_

# include	"IMutex.hh"
# include	"ICondVar.hh"

class			CondVar : public ICondVar
{
public:
  CondVar(IMutex& m);
  ~CondVar(void);

  virtual void		wait(void);
  virtual void		signal(void);
  virtual void		broadcast(void);

private:
  CondVar(const CondVar&);
  CondVar& operator=(const CondVar&);

protected:
  pthread_cond_t	_cond;
  IMutex&		_mutex;
};

#endif		/* !CONDVAR_HH_ */
