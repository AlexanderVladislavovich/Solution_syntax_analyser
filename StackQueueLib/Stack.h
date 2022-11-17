#pragma once
using namespace std;
#include <iostream>

template<typename T>
class stack
{
  int maxsize = 0;
  int size = -1;
  T* mem;

private:
  stack(int m_size);
  ~stack();
  bool IsEmpty();
  bool IsFull();
  void push(T a);
  void pop();
  T top();
  int getsize();

};