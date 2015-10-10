/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/9/15
* Last Modification Date: 10/9/15
* Filename:				Row.inc
*
* Overview:  Provides the function implementation for the Row class.  
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

/**************************************************************
*   Entry:  2D array with the row
*           
*   Exit:  Insantiates an array of rows
*    	      
*   Purpose:  To set up the row class, so that it can return
*			  an overloaded operator[].
*
***************************************************************/
template <class T>
Row<T>::Row(Array2D<T>& f_array2D, int row) : m_array2D(f_array2D), m_row(row)
{


}

/**************************************************************
*   Entry:  A column integer is passed in
*           
*   Exit:  Returns a row and column to select
*		   		      	      
*   Purpose:  Returns an overloaded operator to combine with
*			  the array overloaded operator, in order to select
*			  an element within a 2D array.
*
***************************************************************/
template <class T>
T &Row<T>::operator[](int column)
{
	return m_array2D.Select(m_row, column);

}
