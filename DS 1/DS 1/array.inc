/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/9/15
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
*****************************************************************/

#include <iostream>

#include "array.h"

using namespace std;

/**************************************************************
*   Entry:  The length and start_index are entered to establish 
*           the size of the array
*
*    Exit:  If the length is valid, creates the array
*    	      
* Purpose:  To create an array
*
***************************************************************/
template <class T>
Array<T>::Array(int length, int start_index) : 
  m_length(length),
  m_start_index(start_index)
{
  //  Allocates memory to m_array, making it the size of m_length
  m_array = ( new T[m_length] );

  //  If the array has a 0 or negative length it isn't valid
  //  This throws an Exception under those circumstances.
  if(m_length < 1)
  {
	  throw Exception("Array length is too small");
  }

}


/**************************************************************
*   Entry:  Object with allocated memory
*           
*    Exit:  After deletion of all objects
*    	      
* Purpose:  To clean up memory use, to prevent memory leaks
*
***************************************************************/
template <class T>
Array<T>::~Array()
{
  //  if there's an m_array, this will delete it
  if(m_array)
  {
  delete [] m_array;
  }
}


/**************************************************************
*   Entry:  Takes a reference to another array
*           
*   Exit:  Sets one array equal to another
*    	      
*   Purpose:  To provide functionality to the = operator
*			  so we can set one array equal to another
*
***************************************************************/
template <class T>
Array<T> &Array<T>::operator =(const Array &rhs)
{
  //  If you try and set something equal to itself
  //  it will return the original, and not copy it.
  if (this == &rhs)
    return *this;

  //  Deletes the old array
  delete [] m_array;
  
  //  Setting the length and index to the other array's values
  m_length = rhs.m_length;
  m_start_index = rhs.m_start_index;

  //  Re-creates the array with the new size
  m_array =  new T[m_length];

  //  Loops through each element in both arrays, copying the contents
  //  into the new array
  for(int i = m_start_index; i < (m_start_index + m_length); ++i)
  {
    m_array[i] = rhs.m_array[i];
  }

  // Returns the new array
  return *this;
}

/**************************************************************
*   Entry:  An index number, of integer value
*           
*   Exit:  Returns an element of an array
*    	      
*   Purpose:  To overload the [] operator to set array elements.
*			  If the index values are invalid it throws an exception.
*			  If the values are negative it will compensate.
*
***************************************************************/
template <class T>
T &Array<T>::operator [](int idx)
{
  //  If the index passed is lower than the starting index
  //  it throws an Exception.
  if(idx < m_start_index)
  {
    throw Exception("Index is too low");
  }

  //  If the index passed is greater than or equal to the length
  //  plus the starting index, then it's too big and it throws an
  //  exception.
  if(idx >= (m_length + m_start_index))
  {
	throw Exception("Index is too high");
  }

 
  //  If the starting index is negative, the index subtracts
  //  the starting index.
  if(m_start_index < 0)
  {
	idx = (idx - m_start_index);
	return m_array[idx];
  }

  //  If the starting index is greater than zero, the index
  //  adds the starting index.
  if(m_start_index > 0)
  {
    idx = (idx + m_start_index);
	return m_array[idx];
  }
 
  //  For any other valid values, it returns the array element.
  return m_array[idx];

}

/**************************************************************
*   Entry:  An index number of integer value
*           
*   Exit:  It's a void function, returning nothing at exit
*    	      
* Purpose:  Sets the starting index to the index value given
*
***************************************************************/
template <class T>
void Array<T>::setStartIndex(int index)
{
  m_start_index = index;
}


/**************************************************************
*   Entry:  A length with integer value 
*           
*   Exit:  It's a void function, returning nothing at exit
*    	      
*   Purpose:  Sets the length of an existing array to any 
*			  non-negative integer.  If the new length is
*			  bigger than the existing array, it will copy 
*			  the contents over except for the new elements.
*			  If the new length is smaller, it shrinks the array.
*
***************************************************************/
template <class T>
void Array<T>::setLength(int length)
{
  //  Creates a temporary array with length that's passed in
  T *t_array = ( new T[length] );

  //  If the new length is smaller than the original length
  //  it loops through the contents up to the new length
  //  copying the contents of the array into the temporary one.  
  if(length < m_length)
  for(int i = 0; i < length; ++i)
  {
    t_array[i] = m_array[i];
  }

  //  If the new length is bigger than the original, this copies
  //  the contents of the array into the temporary one, until
  //  it reaches the end of the original array
  if(length > m_length)
  for(int i = 0; i < m_length; ++i)
  {
    t_array[i] = m_array[i];
  }

  //  Deletes the original array
  delete [] m_array;

  //  Sets the array equal to the temporary array
  m_array =  t_array;

  //  If the new length is smaller than the original length
  //  this will copy the temporary array contents into the 
  //  original array, up until it reaches the end of new length.
  if(length < m_length)
  for(int i = 0; i < length; ++i)
  {
    m_array[i] = t_array[i];
  }

  //  If the new length is bigger, it will copy the contents
  //  of the temporary array into the original, until it reaches
  //  the original length.
  if(length > m_length)
  for(int i = 0; i < m_length; ++i)
  {
    m_array[i] = t_array[i];
  }

  //  sets the length of the original array to the new size
  m_length = length;
  
}