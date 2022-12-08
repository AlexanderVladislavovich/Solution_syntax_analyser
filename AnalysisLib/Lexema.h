#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <queue> 
//#include "Errors.h"
#include "ElementTypes.h"
using namespace std;


class Lexema
{
	string str;
	TypeElem type;

public:

	Lexema(string _str, TypeElem _type) : str(_str), type(_type) {};

	string getStr() { return str; }

	TypeElem getType() { return type; }

	friend ostream& operator << (ostream& out, Lexema& p)
	{
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
		}
		else if (p.type == Value) {
			out << "value";
		}
		else if (p.type == Floatp)
		{
			out << "float";
		}
		else if (p.type == UnOP)
		{
			cout << "unary operation";
		}
		out << "}";
		return out;
	}

	int Priority()
	{
		if (type == Operation)
		{
			if (str == "(" || str == ")") return 0;
			if (str == "+" || str == "-") return 1;
			if (str == "*" || str == "/") return 2;
			if (str == "^") return 3;
		}
		if (type == UnOP)
		{
			return 4;
		}
		return -1;
	}
};