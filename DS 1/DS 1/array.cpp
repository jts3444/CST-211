#include <iostream>

#include "array.h"


using namespace std;

template <class T>
Array<T>::Array(int length, int start_index) : 
  m_length(length),
  m_start_index(start_index)
{
  m_array = ( new T[length] );
}

template <class T>
Array<T>::~Array()
{
  delete [] m_array;
}

template <class T>
Array<T>::Array<T> &operator =(const Array &rhs)
{
  if (this == &rhs)
    return *this;

  delete m_array
  
  m_array = ( new T[length] );

  m_array  =  rhs.m_array;
}

//template <class T>
//T &Array<T>::operator[](int idx)
//{
//  //check(idx);
//  //return Array<T>::operator[](idx);
//}

//template <class T>
//void Array<T>::check(int idx) const
//{
//  if((idx < m_length) || idx > m_length)
//	  cout << "Exception";
//}

template <class T>
void Array<T>::setStartIndex(int index)
{
  m_start_index = index;
}

template <class T>
void Array<T>::setLength(int length)
{
  m_length = length;
}

