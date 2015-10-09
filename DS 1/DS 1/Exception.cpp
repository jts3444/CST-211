/******************************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/9/15
* Filename:				Exception.cpp
*
* Overview:  Provides the function implementation for the Exception class.  
*           
*		 
* Input:   The Exception class takes a message that is passed into the class.
*		   
*	 			
* Output:  An error message, depending on the error involved, will be output.
*		   If no error message is passed and the Exception class is used	
*		   a standard error message will be output. 
*		 		 
*******************************************************************************/


#include "array.h"
#include "Exception.h"

/**************************************************************
*   Entry:  No input
*           
*   Exit:  Outputs an error message
*    	      
*   Purpose:  Default constuctor, with a default error message
*
***************************************************************/
Exception::Exception()
{
  m_msg = "Error";
}


/**************************************************************
*   Entry:  Takes a message
*           
*   Exit:  Sets m_msg to the message passed in
*    	      
*   Purpose:  To have error messages in the Exception class
*
***************************************************************/
Exception::Exception(char* msg) : m_msg(msg)
{
}


/**************************************************************
*   Entry:  A message to copy
*           
*   Exit:  No output
*    	      
*   Purpose:  Provides a way to copy an object from the class
*
***************************************************************/
Exception::Exception(const Exception &rhs) : m_msg(rhs.m_msg)
{

}


/**************************************************************
*   Entry:  None
*           
*   Exit:  None
*    	      
*   Purpose:  None
*
***************************************************************/
Exception::~Exception()
{

}


/**************************************************************
*   Entry:  Takes a reference to an exception
*           
*   Exit:  Returns exception message
*    	      
*   Purpose:  To have error messages in the Exception class
*
***************************************************************/
Exception &Exception::operator=(const Exception &rhs)
{
  m_msg = rhs.m_msg;
  return *this;
}


/**************************************************************
*   Entry:  Takes a message
*           
*   Exit:  Sets m_msg to the message passed in
*    	      
*   Purpose:  To set the error message
*
***************************************************************/
void Exception::setMessage(char* msg)
{
  m_msg = msg;
}


/**************************************************************
*   Entry:  Stream and Exception reference
*           
*   Exit:  Returns a stream
*    	      
*   Purpose:  To stream the error messages from Exception class
*
***************************************************************/
ostream& operator<<(ostream &stream, Exception &rhs)
{
	stream << rhs.getMessage();
	return stream;
}

