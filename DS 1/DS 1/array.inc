/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/3/15
* Filename:				array.inc
*
* Overview:  Provides the function implementation for the array class.  
*           
*		 
* Input: The array takes a length and a starting index.  
*		 The class is a template class so that the user  
*	     can have an array of different types of data.
*		
*		
* Output: Output will depend on how the main program calls
*		  these functions.  	
*		
*		 		 
*****************************************************************/



#include <iostream>

#include "array.h"


using namespace std;

template <class T>
Array<T>::Array(int length, int start_index) : 
  m_length(length),
  m_start_index(start_index)
{
  
  if(m_length < 1)
  {
	  throw Exception("Array length is too small");
  }

  m_array = ( new T[length] );
}

template <class T>
Array<T>::~Array()
{
  delete [] m_array;
}

template <class T>
Array<T> &Array<T>::operator =(const Array &rhs)
{
  if (this == &rhs)
    return *this;

  delete m_array;
  
  m_length = rhs.m_length;
  m_start_index = rhs.m_start_index;

  m_array =  new T[m_length];

  for(int i = m_start_index; i < (m_start_index + m_length); ++i)
  {
    m_array[i] = rhs.m_array[i];
  }
  
  //m_array = rhs.m_array;

  return *this;
}

template <class T>
T &Array<T>::operator [](int idx)
{
  if(idx < m_start_index)
  {
    throw Exception("Index is too low");
  }

  if(idx >= (m_length + m_start_index))
  {
	throw Exception("Index is too high");
  }

  //if(m_start_index < 0)
  //{
  //  idx = ((idx - 1) + m_start_index);
  //}

  //if(m_start_index > 0)
  //{
	 //idx = ((idx - 1) - m_start_index);
  //}

  return m_array[idx];

}

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