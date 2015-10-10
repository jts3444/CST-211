/******************************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/3/15
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
	Array2D<int> A(3, 3);

	A.Select(0, 0) = 5;
	A.Select(2, 2) = 6;

	cout << A[0][0] << endl;  

	Array2D<int> B(3,3);

	B = A;

	cout << B[0][0] << endl;
	cout << B[2][2] << endl;

}

