#pragma once
//#include "../AnalysisLib/syntax.cpp"
#include "../AnalysisLib/ReversePolish.h"
#include "../AnalysisLib/Calculator.h"
//#include "../AnalysisLib/Errors.h"
//#include "..//AnalysisLib/Lexema.h"
#include "..//AnalysisLib/Syntax.cpp"
#include "..//AnalysisLib/Errors.h"
int main()
{
  try
  {
    double result;
    string str = "(-(15.25 + 4.75) / ( 100 - 98 ))^2";              
    //string str = "(-10 *  ) * (9 / 3)";
    //string str = " ( 15  + 10 ) * 2";
    cout << "input:  " << str << endl;
    queue<Lexema> q1;
    queue<Lexema> q2;
    q1 = lex(str);
    print(q1);
    cout << endl;
    q2 = postfix(q1);
    cout << "postfix:  ";
    postfixprint(q2);
    result = calcutator(q2);
    cout << "result:  " << result << endl;
  }
  catch(Errors& a)
  {
    a.GetException(); 
  }
  return 0;
}