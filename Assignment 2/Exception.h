/************************************************************************
* Author:				Jason Schmidt
* Date Created:			10/9/15
* Last Modification Date: 10/9/15
* Filename:				Exception.h
*
* Overview:  Provides the function declarations for the Exception class
*           
*		 
* Input: The exception class takes a message 
*		 
*	     	
* Output: Outputs an error message, depending on which message is thrown
*		   	
*		
*		 		 
*************************************************************************/
#include <iostream>

using namespace std;

class Exception
{
  //  overloaded << operator
  friend ostream &operator<<(ostream& stream, Exception &rhs);

  public:

	//  default constructor
    Exception();

	//  constructor that takes a message
    Exception(char *msg);

	//  copy constructor
    Exception(const Exception &rhs);

	//  deconstructor
    ~Exception();

	//  operator overload for =
	Exception &operator=(const Exception &rhs);

	//  gets the error message
	const char* getMessage() {return m_msg;}

	//  sets the error message
    void setMessage(char *msg);
    //operator <<(in stream : ostream &, in except : const Exception &) : ostream &;

    private:
      char* m_msg;		//  variable to hold the message contents
};