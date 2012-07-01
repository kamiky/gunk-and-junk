#pragma once

template<typename T>
struct FunctionSignature
{
  typedef T type;
};

template<typename R>
struct FunctionSignature<R (void)>
{
  typedef R (*type)(void);
  typedef R returnType;
};

template<typename R, typename ARG1>
struct FunctionSignature<R (ARG1)>
{
  typedef R (*type)(ARG1);
  typedef R returnType;
};

template<typename R, typename ARG1, typename ARG2>
struct FunctionSignature<R (ARG1, ARG2)>
{
  typedef R (*type)(ARG1, ARG2);
  typedef R returnType;
};

template<typename R, typename ARG1, typename ARG2, typename ARG3>
struct FunctionSignature<R (ARG1, ARG2, ARG3)>
{
  typedef R (*type)(ARG1, ARG2, ARG3);
  typedef R returnType;
};

template<typename R, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct FunctionSignature<R (ARG1, ARG2, ARG3, ARG4)>
{
  typedef R (*type)(ARG1, ARG2, ARG3, ARG4);
  typedef R returnType;
};
