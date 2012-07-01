#pragma once

template<typename T>
class Function
{};

////////////////////
// SPECIALISATION //
////////////////////

/**
 ** NO ARGUMENTS
 **/
template<typename R>
class Function<R ()>
{
  class IVal {
  public:
    virtual ~IVal() {}
    virtual R operator()() = 0;
  };

  template<typename A>
  class Val : public IVal {
    A	content;
  public :
    Val(A val) : content(val) {}   
    R	operator()() { return content(); }
  };
public:
  Function(){val=NULL;}
  template<typename B> Function(const B & oth){ val = new Val<B>(oth);}
  template<typename B>
  const B & operator=(const B & oth)
  {
    if (val!=NULL)
      delete val;
    val = new Val<B>(oth);
    return oth;
  }
  R operator()() { return (*val)(); }
private :
  IVal		*val;
};

/**
 ** 1 ARGUMENTS
 **/
template<typename R, typename ARG1>
class Function<R (ARG1)>
{
  class IVal {
  public:
    virtual ~IVal() {}
    virtual R operator()(ARG1) = 0;
  };

  template<typename A>
  class Val : public IVal {
    A	content;
  public :
    Val(A val) : content(val) {}   
    R	operator()(ARG1 a) { return content(a); }
  };
public:
  Function(){val=NULL;}
  template<typename B> Function(const B & oth){ val = new Val<B>(oth);}
  template<typename B>
  const B & operator=(const B & oth){
    if (val!=NULL)
      delete val;
    val = new Val<B>(oth);
    return oth;
  }
  R operator()(ARG1 a) { return (*val)(a); }
private :
  IVal		*val;
};

/**
 ** 2 ARGUMENTS
 **/
template<typename R, typename ARG1, typename ARG2>
class Function<R (ARG1, ARG2)>
{
  class IVal {
  public:
    virtual ~IVal() {}
    virtual R operator()(ARG1, ARG2) = 0;
  };

  template<typename A>
  class Val : public IVal {
    A	content;
  public :
    Val(A val) : content(val) {}   
    R	operator()(ARG1 a, ARG2 b) { return content(a,b); }
  };
public:
  Function(){val=NULL;}
  template<typename B> Function(const B & oth){ val = new Val<B>(oth);}
  template<typename B>
  const B & operator=(const B & oth){
    if (val!=NULL)
      delete val;
    val = new Val<B>(oth);
    return oth;
  }
  R operator()(ARG1 a, ARG2 b) { return (*val)(a,b); }
private :
  IVal		*val;
};

/**
 ** 3 ARGUMENTS
 **/
template<typename R, typename ARG1, typename ARG2, typename ARG3>
class Function<R (ARG1, ARG2, ARG3)>
{
  class IVal {
  public:
    virtual ~IVal() {}
    virtual R operator()(ARG1, ARG2, ARG3) = 0;
  };

  template<typename A>
  class Val : public IVal {
    A	content;
  public :
    Val(A val) : content(val) {}   
    R	operator()(ARG1 a, ARG2 b, ARG3 c) { return content(a,b,c); }
  };
public:
  Function(){val=NULL;}
  template<typename B> Function(const B & oth){ val = new Val<B>(oth);}
  template<typename B>
  const B & operator=(const B & oth){
    if (val!=NULL)
      delete val;
    val = new Val<B>(oth);
    return oth;
  }
  R operator()(ARG1 a, ARG2 b, ARG3 c) { return (*val)(a,b,c); }
private :
  IVal		*val;
};

/**
 ** 4 ARGUMENTS
 **/
template<typename R, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
class Function<R (ARG1, ARG2, ARG3, ARG4)>
{
  class IVal {
  public:
    virtual ~IVal() {}
    virtual R operator()(ARG1, ARG2, ARG3, ARG4) = 0;
  };

  template<typename A>
  class Val : public IVal {
    A	content;
  public :
    Val(A val) : content(val) {}   
    R	operator()(ARG1 a, ARG2 b, ARG3 c, ARG4 d) { return content(a,b,c,d); }
  };
public:
  Function(){val=NULL;}
  template<typename B> Function(const B & oth){ val = new Val<B>(oth);}
  template<typename B>
  const B & operator=(const B & oth){
    if (val!=NULL)
      delete val;
    val = new Val<B>(oth);
    return oth;
  }
  R operator()(ARG1 a, ARG2 b, ARG3 c, ARG4 d) { return (*val)(a,b,c,d); }
private :
  IVal		*val;
};
