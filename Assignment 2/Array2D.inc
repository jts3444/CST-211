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
  m_row(row),  //  instantiates m_row to row value passed in
  m_col(col)  //  instantiates m_col to col value passed in
{
  
  //  If the row or column is less than 0, exception thrown
  if(m_row < 0 || m_col < 0)  
  {
	  throw Exception("Array length is too small");
  }

  //  Creates the row part of the array
  m_array = ( new T*[m_row] );

  //  loops through the row, creating a column for each row
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
  //  If there is an array object, it deletes
  if(m_array != NULL)
  {
	//  goes through each row, deleting elements within
	for(int i = 0; i < m_row; i++)
    {
      delete [] m_array[i];
	}

	//  deletes the remainder
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
  //  Performs a self check
  if (this == &rhs)
    return *this;

  //  Delete the row elements
  for(int i = 0; i < m_row; i++)
  {
    delete [] m_array[i];
  }

  //  Deletes the rest of the array
  delete [] m_array;
  
  m_row = rhs.m_row;  //  Sets the row to new row length
  m_col = rhs.m_col;  //  Sets the col to new col length
  
  //  Creates new array with new row amount
  m_array = ( new T*[m_row] );  

  //  Loops through the rows and creates columns
  for(int i = 0; i < m_row; i++)
	  m_array[i] = new T[m_col];

  //  Copies the contents of one array into the other
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
  //  Checks index values, if they're too high, throws exception
  if(idx >= (m_row) || idx >=(m_col))
  {
	throw Exception("Index is too high");
  }

  //  Creates an element
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
  //  Creates temporary 2D array
  T **c_array = ( new T*[col] );

  //  Finishes the creation process for temporary array
  for(int i = 0; i < col; i++)
	  c_array[i] = new T[m_col];

  //  Copies the contents of one array into the other
  //  If the new column is less than the old it only 
  //  loops through the smaller amount
  if(col < m_col)
  {
    for(int i = 0; i < col; i++)
    {
	  for(int idx = 0; idx < m_row; idx++)
	  {
		  c_array[i][idx] = m_array[i][idx];
	  }
    }
  }

  //  If the new column is greater than the old
  //  It only loops through the old column value
  if(col > m_col)
  {
	for(int i = 0; i < m_col; i++)
    {
	  for(int idx = 0; idx < m_row; idx++)
	  {
		  c_array[i][idx] = m_array[i][idx];
	  }
    }
  }

  //  Deletes the old array
  for(int i = 0; i < m_row; i++)
    {
      delete [] m_array[i];
	}

	//  deletes the remainder
    delete [] m_array;

	//  Sets the array equal to the temporary one
	m_array = c_array;

  m_col = col;  
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
  //  Creates temporary row array
  T **r_array = ( new T*[row] );

  //  Finishes the creation of the 2D temp array
  for(int i = 0; i < row; i++)
	  r_array[i] = new T[m_col];

  //  Copies the contents of one array into the other
  //  If the new row value is less, it loops through
  //  the smaller amount
   if(row < m_row)
  {
    for(int i = 0; i < row; i++)
    {
	  for(int idx = 0; idx < m_col; idx++)
	  {
		  r_array[i][idx] = m_array[i][idx];
	  }
    }
  }

  //  If the new row amount is greater it only
  //  loops through the older value
  if(row > m_row)
  {
	for(int i = 0; i < m_row; i++)
    {
	  for(int idx = 0; idx < m_col; idx++)
	  {
		  r_array[i][idx] = m_array[i][idx];
	  }
    }
  }

  //  Deletes old array
  for(int i = 0; i < m_col; i++)
    {
      delete [] m_array[i];
	}

	//  deletes the remainder
    delete [] m_array;

	//  Sets array equal to temp array
	m_array = r_array;

  //  Creates new array with new row amount
  
    m_row = row; 
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
	//  Returns a selection within the 2D array
	return m_array[row][col];

}