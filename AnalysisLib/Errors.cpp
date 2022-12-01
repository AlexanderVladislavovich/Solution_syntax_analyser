#pragma once
#include "Syntax.cpp"
#include <iostream>
using namespace std;


class Errors
{
public:
  virtual void GetException() = 0;
};

class UnexpectedOpertation :public Errors
{
  Lexema l;
public:
  UnexpectedOpertation(Lexema _l) :l(_l) {}
  void GetException()
  {
		cout << "Unexpected operation" << ':' << l.getStr() << endl;
  }

};
class MissingOperator :public Errors
{
  Lexema l;
public:
  MissingOperator(Lexema _l) :l(_l) {}
  void GetException()
  {
    cout << "Missing operator" << ':' << l.getStr() << endl;
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