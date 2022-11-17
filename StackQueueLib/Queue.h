#pragma once
using namespace std;
#include <iostream>

template<typename T>
class queue
{
  T* mem;
  int* start;
  int* end;
  int size;
private:
  queue(int s = 0);
  int next(int a);
  void push(T a);
  int pop();
  bool IsEmpty();
  bool IsFull();
  ~queue();
};