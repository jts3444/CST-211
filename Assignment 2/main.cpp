/******************************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/10/15
* Filename:				main.cpp
*
* Overview:  The main program is linked to the array and exception classes.  
*            It will use both classes to initiate an array and copy an array 
*		     into another array.  If there is an error it will output an error 
*			 and end the program.
*
* Input:   The input will be up to the user to decide.
*		   
*	 		
* Output:  
*		   	
*		    		 		 
*******************************************************************************/

#include "Array2D.h"
#include "Exception.h"
#include <iostream>

using namespace std;

int main()
{
	// Creates integer array, A
	Array2D<int> A(3, 3);

	//  Setting elements 
	A.Select(0, 0) = 5;
	A.Select(2, 2) = 6;

	//  Ensuring the data was input correctly
	cout << "Should be 5: " << A[0][0] << endl;  
	cout << "Should be 6: " << A[2][2] << endl;

	//  Creating integer array, B
	Array2D<int> B(3,3);

	//  Testing the = overload
	B = A;

	//  Checking to ensure A was copied to B
	cout << "Should be 5: " << B[0][0] << endl;
	cout << "Should be 6: " << B[2][2] << endl;

	B.setColumn(4);
	B.setRow(4);

	B.Select(3,3) = 7;

	cout << "Should be 7: " << B[3][3] << endl;


}

