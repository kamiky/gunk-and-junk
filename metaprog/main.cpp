#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include "Function.hpp"

class Callable
{
public :
  int	operator()(int b)
  {
    std::cout << "Callable Object with argument : " << b << std::endl;
    return b;
  }
};

int	myfunction(const char *str)
{
  std::cout << "function with argument : " << str << std::endl;
  return 1;
}

void	myfunction2(const char *str, int a, int b)
{
  (void)a;
  (void)b;
  std::cout << "function called with boost::bind : " << str << std::endl;
}

int	main()
{
  Callable	b;

  std::cout << "[TEST1]" << std::endl;
  Function<int (int)> f;
  f = b;
  f(2);

  std::cout << "\n[TEST2]" << std::endl;
  Function<int (const char *)> f2;
  f2 = &myfunction;
  f2("hello world");

  std::cout << "\n[TEST3]" << std::endl;
  Function<void (const char *, int, int)> f3;
  f3 = &myfunction2;
  f3("hello world again",1,2);


  std::cout << "\n[TEST4 Calling test2 through a functor]" << std::endl;
  Function<int (const char *)> f4(f2);
  f4("yet another hello world");

  return 0;
}
