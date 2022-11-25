
//#include "../AnalysisLib/syntax.cpp"
#include "../AnalysisLib/ReversePolish.cpp"

int main()
{
  //string str = "(15 + 2) / 6";              
  string str = "(15 * 10 - 70) * (90 / 3)";
  cout <<"input:"<< "\n" << str << endl;
  queue<Lexema> q1;
  queue<Lexema> q2;
  q1 = lex(str);
  print(q1);
  cout << endl;
  q2 = postfix(q1);
  cout << "result:" << endl;
  postfixprint(q2);
  return 0;
}