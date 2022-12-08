#pragma once
#include <stack>
#include <queue>
//#include "Syntax.cpp"
#include "Lexema.h"

//double calcutator(queue<Lexema> q)
//{
//	double tmp = 0;
//	stack<Lexema> copy,b;
//	int s = q.size();
//	for (int i = 0; i < s; i++)
//	{
//		copy.push(q.front());
//		//b.push(a.top());
//		q.pop();
//	}
//	for (int i = 0; i < s; i++)
//	{
//		b.push(copy.top());
//		copy.pop();
//	}
//	while (b.size() != 1)
//	{
//		Lexema operand1 = b.top();
//		b.pop();
//		if (b.top().getType() == Value || b.top().getType() == Floatp)
//		{
//			Lexema operand2 = b.top();
//			b.pop();
//			if (b.top().getType() == UnOP) 
//			{
//				Lexema operand2_2('-' + operand2.getStr(), operand2.getType());
//				operand2 = operand2_2;
//				b.pop();
//			}
//
//			while (!(b.top().getType() != Operation || b.top().getType() != UnOP))
//			{
//				operand1 = operand2;
//				operand2 = b.top();
//				b.pop();
//			}
//			Lexema operator1 = b.top();
//			b.pop();
//			if (operator1.getStr() == "+")
//			{
//				tmp = stod(operand1.getStr()) + stod(operand2.getStr());
//			}
//			else if (operator1.getStr() == "-")
//			{
//				tmp = stod(operand1.getStr()) - stod(operand2.getStr());
//			}
//			else if (operator1.getStr() == "*")
//			{
//				tmp = stod(operand1.getStr()) * stod(operand2.getStr());
//			}
//			else if (operator1.getStr() == "/")
//			{
//				tmp = stod(operand1.getStr()) / stod(operand2.getStr());
//			}
//			else
//				tmp = pow(stod(operand1.getStr()), stod(operand2.getStr()));
//		}
//		else if (b.top().getType() == UnOP)
//		{
//			Lexema operator1 = b.top();
//			b.pop();
//			tmp = -(stod(operand1.getStr()));
//		}
//		Lexema l(to_string(tmp), Floatp);
//		b.push(l);
//	}
//	return tmp;
//}
Lexema calc(Lexema operand1, Lexema operand2, Lexema operator1);
Lexema calc(Lexema operand);

double calcutator(queue<Lexema> q)
{
	double tmp = 0;
	stack<Lexema> copy, b;
	int s = q.size();
	for (int i = 0; i < s; i++)
	{
		copy.push(q.front());
		//b.push(a.top());
		q.pop();
	}
	for (int i = 0; i < s; i++)
	{
		b.push(copy.top());
		copy.pop();
	}
	while (b.size() != 1)
	{
		Lexema op1 = b.top();
		b.pop();
		Lexema op2 = b.top();
		b.pop();
		Lexema op3 = b.top();
		b.pop();
		if ((op1.getType() == Value || op1.getType() == Floatp) && op2.getType() == UnOP && op3.getType() == Operation)  throw MissingOperand( op3, "Missing operand");
		if ((op1.getType() == Value || op1.getType() == Floatp) && op2.getType() == Operation)  throw MissingOperand(op2, "Missing operand");

		while (     !(((op2.getType() == Value || op2.getType() == Floatp ) && op3.getType() == Operation ) || (op2.getType() == UnOP))     )
		{
			copy.push(op1);
			op1 = op2;
			op2 = op3;
			op3 = b.top();
			b.pop();
 		}
		//if ((op1.getType() == Value || op1.getType() == Floatp) && op2.getType() == Operation) throw MissingOperand( op2 , "Missing operand");
		if (op2.getType() == UnOP)
		{
			Lexema l = calc(op1);
			b.push(op3);
			b.push(l);
		}
		else if (op3.getType() == Operation)
		{
			Lexema l = calc(op1, op2, op3);
			b.push(l);
		}
		while(!copy.empty())
		{
			b.push(copy.top());
			copy.pop();
		}
	}
	tmp = stod(b.top().getStr());
	return tmp;
}

Lexema calc(Lexema operand1, Lexema operand2, Lexema operator1)
{
	float tmp;
	if (operator1.getStr() == "+")
	{
		tmp = stod(operand1.getStr()) + stod(operand2.getStr());
	}
	else if (operator1.getStr() == "-")
	{
		tmp = stod(operand1.getStr()) - stod(operand2.getStr());
	}
	else if (operator1.getStr() == "*")
	{
		tmp = stod(operand1.getStr()) * stod(operand2.getStr());
	}
	else if (operator1.getStr() == "/")
	{
		tmp = stod(operand1.getStr()) / stod(operand2.getStr());
	}
	else
	{
		tmp = pow(stod(operand1.getStr()), stod(operand2.getStr()));
	}
	
	Lexema lex(to_string(tmp), Floatp);
	return lex;
}

Lexema calc(Lexema operand)
{
	float tmp;
	tmp = -(stod(operand.getStr()));
	Lexema lex( to_string(tmp), Floatp);
	return lex;
}