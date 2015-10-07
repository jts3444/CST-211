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
*		
* Output:  
*		   	
*		    
*		 		 
*******************************************************************************/



#include "array.h"
#include <iostream>


using namespace std;

int main()
{
  try
  {
  Array<int> A(5, -2);
  A[-1] = 4;
  A[1] = 9;
  A[0] = 33;

  cout << A[-1] << endl;
  cout << A[1] << endl;
  cout << A[0] << endl;

  Array<int> B(5, 0);
  //B = A;

  B[2] = 10;
  B[1] = 11;
  B[0] = 12;

  cout << B[2] << endl;
  cout << B[1] << endl;
  cout << B[0] << endl;

  Array<int> C(5, 0);

  C[2] = 2;
  cout << C[2];

  }
  
  catch(Exception &a)
  {
	  cerr << "Error: " << a.getMessage() << endl;
	
  }

  return 0;
}

