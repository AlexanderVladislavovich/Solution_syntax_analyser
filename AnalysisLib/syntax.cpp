#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <queue> 
//#include "Errors.cpp"
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

queue <Lexema> lex(string input)
{
	queue<Lexema>res;
	input += ' ';
	int i = 0;
	string tmp = "";
	string binop = "+-*/()^";
	string unop = "-";
	string sep = " \n\t";
	int state = 0;
	int open = 0, close = 0;

	for (i = 0; i < input.size(); i++)
	{
		char c = input[i];
		int fres;
		switch (state)
		{
		case 0:
			if (c >= '0' && c <= '9')
			{
				tmp = c;
				state = 1;
				break;
			}

			if (c == '-' && (res.empty() || res.back().getType() == Operation))
			{
				tmp = c;
				Lexema l(tmp, UnOP);
				res.push(l);
				state = 0;
				break;
			}
			fres = binop.find(c);
			if (fres >= 0)
			{
				if (c == '(') open += 1;
				if (c == ')') close += 1;
				tmp = c;
				Lexema l(tmp, Operation);
				res.push(l);
				break;
			}
			break;
		case 1: //число
			if (c >= '0' && c <= '9')
			{
				tmp += c;
				state = 1;
				break;
			}
			if (c == '.')
			{
				tmp += c;
				state = 2;
				break;
			}
			fres = binop.find(c);
			if (fres >= 0)
			{
				if (c == '(') open += 1;
				if (c == ')') close += 1;
				Lexema l1(tmp, Value);
				res.push(l1);
				tmp = c;
				Lexema l2(tmp, Operation);
				res.push(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);
			if (fres >= 0)
			{
				Lexema l(tmp, Value);
				res.push(l);
				state = 0;
				break;
			}
			break;
		case 2:  //дробная часть
			if (c >= '0' && c <= '9')
			{
				tmp += c;
				state = 3;
				break;
			}

			throw - 1;
		case 3:  //число с плав. точкой
			if (c >= '0' && c <= '9')
			{
				tmp += c;
				state = 3;
				break;
			}
			fres = binop.find(c);
			if (fres >= 0)
			{
				if (c == '(') open += 1;
				if (c == ')') close += 1;
				Lexema l(tmp, Floatp);
				res.push(l);
				state = 0;
				break;
			}
			fres = sep.find(c);
			if (fres >= 0)
			{
				Lexema l(tmp, Floatp);
				res.push(l);
				state = 0;
				break;
			}
		}
		
	}
	if (close < open) throw - 1;
	if (close > open) throw - 1;
	return res;
}
void print(queue <Lexema> t) 
{
	while (!t.empty()) {
		cout << t.front() << endl;
		t.pop();
	}
}
