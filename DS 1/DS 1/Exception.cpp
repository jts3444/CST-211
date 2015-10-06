/******************************************************************************
* Author:				Jason Schmidt
* Date Created:			10/3/15
* Last Modification Date: 10/3/15
* Filename:				Exception.cpp
*
* Overview:  Provides the function implementation for the Exception class.  
*           
*		 
* Input:   The Exception class takes a message that is passed into the class.
*		   
*	 	
*		
* Output:  An error message, depending on the error involved, will be output.
*		   If no error message is passed and the Exception class is used	
*		   a standard error message will be output. 
*		 		 
*******************************************************************************/



#include "array.h"

Exception::Exception()
{
  m_msg = "Error";
}
Exception::Exception(char* msg) : m_msg(msg)
{
}

Exception::Exception(const Exception &rhs) : m_msg(rhs.m_msg)
{

}

Exception::~Exception()
{

}

Exception &Exception::operator=(const Exception &rhs)
{
  m_msg = rhs.m_msg;
  return *this;
}

void Exception::setMessage(char* msg)
{
  m_msg = msg;
}

