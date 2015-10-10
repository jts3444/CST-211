/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/9/15
* Last Modification Date: 10/9/15
* Filename:				Row.h
*
* Overview:  Provides the function declarations for the Row  
*            class. 
*			 
*		 
* Input: The array takes a length and a starting index.  
*		 The class is a template class so that the user  
*	     can have an array of different types of data. 
*		 
*	     	
* Output: Output depends on how the main program uses the class.
*		   	
*				 		 
*****************************************************************/
#ifndef Row_H
#define Row_H

template<class T>
class Array2D;

template<class T>
class Row 
{
  public:
    Row(Array2D<T>&, int row);
    T &operator [](int column);
    

  private:
	Array2D<T> &m_array2D; 
	int m_row;
};

#include "Row.inc"
#endif