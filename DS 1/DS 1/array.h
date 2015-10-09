/****************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/9/15
* Filename:				array.h
*
* Overview:  Provides the function declarations for the array class 
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
*		 		 
*****************************************************************/

#include <iostream>
#ifndef array_H
#define array_H

using namespace std;

template<class T>
class Array
{
  public:
	// default constructor
    Array();

	// constructor that takes length and start_index
	// sets start_index to 0 if none is provided.
    Array(int length, int start_index = 0);

	// copy constructor
    Array(const Array<T> &rhs);

	// deconstructor
    ~Array();

	// operator overload for =
    Array <T> &operator =(const Array &rhs);

	// operator overload for []
    T &operator [](int idx);

	// gets the starting index, and returns it 
	int getStartIndex() const {return m_start_index;}

	//  allows the user to set the starting index
    void setStartIndex(int index);

	//  gets the length of the array
	int getLength() const {return m_length;}

	// sets the length of the array
    void setLength(int length);

  private:
    T *m_array;			//  Array of type specified in driver file
    int m_length;		//  length of the array
    int m_start_index;	//  starting index of the array

};

#include "array.inc"

#endif


