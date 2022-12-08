#pragma once
//#include "Syntax.cpp"
#include <iostream>
#include "Lexema.h"
using namespace std;


class Errors
{
public:
  virtual void GetException() = 0;
};

class UnexpectedOpertation :public Errors
{
  Lexema l;
  string what;
public:
  UnexpectedOpertation(Lexema _l, string _what) :l(_l), what(_what) {}
  void GetException()
  {
		cout << what << ' ' << l.getStr() << endl;
  }

};
class MissingOperator :public Errors
{
  Lexema l;
  string what;
public:
  MissingOperator(Lexema _l, string _what) :l(_l), what(_what) {}
  void GetException()
  {
    cout << what << ' ' << l.getStr() << endl;
  }
};

class MissingOperand :public Errors
{
  Lexema l;
  string what;
public:
  MissingOperand(Lexema _l, string _what) : l(_l) ,what(_what) {}
  void GetException()
  {
    cout << what /*<< " " << l.getStr()*/ << endl;
  }
};
//class Exception
//{
//public:
//	virtual void show() = 0;
//};
//
//class ex1 :public Exception
//{
//	char c;
//public:
//	ex1(char _c) :c(_c) {}
//
//	void show()
//	{
//		cout << "error" << ' ' << c << endl;
//	}
//
//};