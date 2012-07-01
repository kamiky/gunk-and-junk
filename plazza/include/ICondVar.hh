//
// ICondVar.hh for plazza in /home/hugues_v//epitech/cpp/tp/tp3_threads
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Sat Apr  9 19:04:55 2011 vincent hugues
// Last update Sat Apr  9 19:07:51 2011 vincent hugues
//

#ifndef		ICONDVAR_HH_
# define	ICONDVAR_HH_

class		ICondVar
{
public:
  virtual void	wait(void) = 0;
  virtual void	signal(void) = 0;
  virtual void	broadcast(void) = 0;
};

#endif		/* !ICONDVAR_HH_ */
