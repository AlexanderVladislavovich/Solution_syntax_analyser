#pragma once
#include <queue>
#include <stack>
#include "../AnalysisLib/syntax.cpp"


queue<Lexema>  postfix(queue<Lexema> a)
{
  stack<Lexema> s1;
  Lexema l1("", NullType);
  queue<Lexema> q1;
  while (!a.empty())
  {
    l1 = a.front();

    if (l1.getType() == Value || l1.getType() == Floatp)
    {
      q1.push(l1);
    }
    else if (l1.getType() == UnOP)
    {
      s1.push(l1);
    }
    else if (l1.getStr() == "(")
    {
      s1.push(l1);
    }
    else if (l1.getStr() == ")")
    {
      while (s1.top().getStr() != "(")
      {
        q1.push(s1.top());
        s1.pop();
      }
      s1.pop();
    }
    else if (l1.getType() == Operation)
    {
      while (!s1.empty())
      {
        if (s1.top().Priority() >= l1.Priority())
        {
          q1.push(s1.top()); s1.pop();
          s1.push(l1);
          break;
        }
        else
        {
          s1.push(l1);
          break;
        }
      }
      if (s1.empty())
      {
        s1.push(l1);
      }
     
    }
    a.pop();
  }
  while (!s1.empty())
  {
    q1.push(s1.top());
    s1.pop();
  }
  return q1;
}

void postfixprint(queue<Lexema> q1)
{
  while (!q1.empty())
  {
    cout << q1.front().getStr() << ' ';
    q1.pop();
  }
  cout << endl;
}