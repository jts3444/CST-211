/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/10/15
* Filename:				Array2D.inc
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

#include "Array2D.h"

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
Array2D<T>::Array2D(int row, int col) : 
  m_row(row),
  m_col(col)
{
  

  if(m_row < 0 || m_col < 0)
  {
	  throw Exception("Array length is too small");
  }

  m_array = ( new T*[m_row] );

  for(int i = 0; i < m_row; i ++)
	  m_array[i] = new T[m_col];
   
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
Array2D<T>::~Array2D()
{
  if(m_array != NULL)
  {
	for(int i = 0; i < m_row; i++)
    {
      delete [] m_array[i];
	}

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
Array2D<T> &Array2D<T>::operator =(const Array2D &rhs)
{
  if (this == &rhs)
    return *this;

  for(int i = 0; i < m_row; i++)
  {
    delete [] m_array[i];
  }

  delete [] m_array;
  
  m_row = rhs.m_row;
  m_col = rhs.m_col;
  
  m_array = ( new T*[m_row] );

  for(int i = 0; i < m_row; i++)
	  m_array[i] = new T[m_col];

  for(int i = 0; i < m_row; i++)
  {
	  for(int idx = 0; idx < m_col; idx++)
	  {
		  m_array[i][idx] = rhs.m_array[i][idx];
	  }
  }

  return *this;
}


/**************************************************************
*   Entry:  An index number, of integer value
*           
*   Exit:  Returns an element of an array
*    	      
*   Purpose:  To overload the [] operator to set array elements.
*			  If the index values are invalid it throws an exception.
*
***************************************************************/
template <class T>
Row<T> Array2D<T>::operator [](int idx)
{

  if(idx >= (m_row) || idx >=(m_col))
  {
	throw Exception("Index is too high");
  }

  Row<T> element(*this, idx);
  return element;

}


/**************************************************************
*   Entry:  A column of integer value
*           
*   Exit:  It's a void function, returning nothing at exit
*    	      
*   Purpose:  Sets the starting column to value given
*
***************************************************************/
template <class T>
void Array2D<T>::setColumn(int col)
{
  m_col = index;
}


/**************************************************************
*   Entry:  An integer value for row
*           
*   Exit:  It's a void function, returning nothing at exit
*    	      
*   Purpose:  Sets the row
*
***************************************************************/
template <class T>
void Array2D<T>::setRow(int row)
{
  m_row = length; 
}


/**************************************************************
*   Entry:  Two integers, one row, one column
*           
*   Exit:  Returns the array selection for column and row
*    	      
*   Purpose:  To select a particular row and element
*
***************************************************************/
template <class T>
T& Array2D<T>::Select(int row, int col)
{
	return m_array[row][col];

}