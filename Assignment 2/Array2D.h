/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/3/15
* Filename:				Array2D.h
*
* Overview:  Provides the function declarations for the Array2D  
*            and the Row class.  The Row class is included because
*			 it is derived from the Array2D class.
*		 
* Input: The array takes a length and a starting index.  
*		 The class is a template class so that the user  
*	     can have an array of different types of data. 
*		 
*	     	
* Output: Output depends on how the main program uses the class.
*		   	
*		
*		 		 
*****************************************************************/

#include "Row.h"
#include <iostream>
#ifndef Array2D_H
#define Array2D_H

using namespace std;

template<class T>
class Array2D
{
  public:  
  
  // Default constructor
  Array2D();
  
  //  Constructor with row and column
  Array2D(int row, int col);

  //  Deconstructor
  ~Array2D();
  
  //  Copy constructor
  Array2D(const Array2D<T> &copy);

  //  Operator overload for =
  Array2D& operator =(const Array2D &rhs);

  //  Operator overload for []
  Row<T> operator [](int index);

  //  Gets the row
  int getRow() const {return m_row;} 

  //  Sets the row
  void setRow(int row);

  //  Gets the column
  int getColumn() const {return m_col;}

  //  Sets the column
  void setColumn(int col);

  T& Select(int row, int col);

  private:

  T **m_array;
  int m_row;
  int m_col;
  
};

#include "Array2D.inc"

#endif
