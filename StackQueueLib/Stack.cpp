
#include "Stack.h"

template<typename T>
stack<T>::stack(int m_size)
{
  maxsize = m_size;
  mem = new T[maxsize];

}

template<typename T>
stack<T>::~stack()
{
  delete[]mem;
}

template<typename T>
void stack<T>::push(T a)
{
  if (size == maxsize - 1)
  {
    cout << "error";
    return;
  }
  size += 1;
  mem[size] = a;
}

template<typename T>
bool stack<T>::IsFull()
{
  if (size == maxsize - 1) return true;
  else return false;

}

template<typename T>
bool stack<T>::IsEmpty()
{
  if (size == -1) return true;
  else return false;
}

template<typename T>
void stack<T>::pop()
{
  mem[size] = 0;
  size -= 1;
}

template<typename T>
int stack<T>::getsize()
{
  return size;
}

template<typename T>
T stack<T>::top()
{
  return mem[size];
}