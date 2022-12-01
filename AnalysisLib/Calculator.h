#pragma once
#include <stack>
#include <queue>
#include "Syntax.cpp"

double calcutator(queue<Lexema> q)
{
	double tmp = 0;
	stack<Lexema> copy,b;
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
		Lexema operand1 = b.top();
		b.pop();
		if (b.top().getType() == Value || b.top().getType() == Floatp)
		{
			Lexema operand2 = b.top();
			b.pop();
			if (b.top().getType() == UnOP) 
			{
				Lexema operand2_2('-' + operand2.getStr(), operand2.getType());
				operand2 = operand2_2;
				b.pop();
			}

			while (!(b.top().getType() != Operation || b.top().getType() != UnOP))
			{
				operand1 = operand2;
				operand2 = b.top();
				b.pop();
			}
			Lexema operator1 = b.top();
			b.pop();
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
				tmp = pow(stod(operand1.getStr()), stod(operand2.getStr()));
		}
		else if (b.top().getType() == UnOP)
		{
			Lexema operator1 = b.top();
			b.pop();
			tmp = -(stod(operand1.getStr()));
		}
		Lexema l(to_string(tmp), Floatp);
		b.push(l);
	}
	return tmp;
}
