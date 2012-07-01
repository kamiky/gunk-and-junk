#include <iostream>
#include "Waiter.hh"
#include "common.hh"

int main()
{
  Waiter wait(0);
  ushort lol;

  if (fork())
    {
      wait.to();
      lol = 42;
      while (lol != 0)
	{
	  if (wait.checkDelivery())
	    {
	      lol = wait.deliver<ushort>();
	      std::cout << "reponse:"
			<< lol << std::endl;
	    }
	}
      return(0);
    }
  else
    {
      wait.from();
      for (ushort i = 10; i >= 0; --i)
	wait.take<ushort>(i);
      return (0);
    }
}
