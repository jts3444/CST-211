/******************************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/9/15
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
*		
* Output:  Array creation, element setting, and output.  Shows use of =operator
*		   shrinking and enlarging array.  Has error message at the end.
*		    
*		 		 
*******************************************************************************/



#include "array.h"
#include "Exception.h"
#include <iostream>


using namespace std;

int main()
{
  try
  {
	//  Creates array of integers, A
    Array<int> A(5, -2);
    A[-1] = 4;
    A[-2] = 9;
    A[0] = 33;

	//  Showing that the array elements set correctly
    cout << "Should equal 4: " << A[-1] << endl;
    cout << "Should equal 9: " << A[-2] << endl;
    cout << "Should equal 33: " << A[0] << endl << endl;

	//  Creates integer array, B
    Array<int> B(5, 0);

	//  Sets B array equal to A
    B = A;

	//  Filling B array
    B[1] = 10;
    B[2] = 11;

    //  Showing the contents of B, the first three are inputs copied from A
    cout << "Should equal 9: " << B[-2] << endl;
    cout << "Should equal 4: " << B[-1] << endl;
    cout << "Should equal 33: " << B[0] << endl;
    cout << "Should equal 10: " << B[1] << endl;
    cout << "Should equal 11: " << B[2] << endl << endl;

	//  Shrinks B from 5 to 3 elements
    B.setLength(3);

	//  Outputs the shrunken array
    cout << "Should equal 9: " << B[-2] << endl;
    cout << "Should equal 4: " << B[-1] << endl;
    cout << "Should equal 33: " << B[0] << endl << endl;

	//  Creating array C
    Array<int> C(5, 0);

	//  Setting element equal to 2
    C[2] = 2;

	//  Outputs the element from C
    cout << "Should equal 2: " << C[2] << endl << endl;

    //  Making C a bigger array
	C.setLength(7);

	//  Making sure the bigger array can allocate to new length
    C[6] = 99;

	//  
    cout << "Should equal 2: " << C[2] << endl;
    cout << "Should equal 99: " << C[6] << endl << endl;

	/*  Uncomment to test if index is too high
    C[7];*/

	//  Tests if index is too low, will throw Exception message
	C[-2];

  }
  
  catch(Exception &a)
  {
	  cerr << "Error: " << a.getMessage() << endl;
  }

  return 0;
}

