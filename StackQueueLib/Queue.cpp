#include "Queue.h"

template<typename T>
queue<T>::queue(int s)
{
  size = s;
  mem = new T[size];
  end = 0;
  start = next(end);
}

template<typename T>
queue<T>::~queue()
{
  delete[]mem;
}

template<typename T>
int queue<T>::next(int a)
{
  return (a + 1) % size;
}

template<typename T>
bool queue<T>::IsEmpty()
{
  return 
}
template<typename T>
bool queue<T>::IsFull()
{
  return 
}
template<typename T>
void queue<T>::push(T a)
{
  end = next(end);
  mem[end] = a;
}
