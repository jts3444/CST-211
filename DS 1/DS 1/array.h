#include <iostream>
#ifndef array_H
#define array_H

using namespace std;

template<class T>
class Array
{
  public:
    Array();
    Array(int length, int start_index = 0);
    Array(const Array<T> &rhs);
    ~Array();
    Array <T> &operator =(const Array &rhs);
    T &operator [](int idx);
	int getStartIndex() const {return m_start_index;}
    void setStartIndex(int index);
	int getLength() const {return m_length;}
    void setLength(int length);

  private:
    T *m_array;
    int m_length;
    int m_start_index;
	//void check(int idx) const;

};


class Exception
{

  friend ostream &operator<<(ostream &os, const Exception &rhs);

  public:
    Exception();
    Exception(char *msg);
    Exception(const Exception &rhs);
    ~Exception();
	Exception &operator=(const Exception &rhs);
	const char* getMessage() {return m_msg;}
    void setMessage(char *msg);
    //operator <<(in stream : ostream &, in except : const Exception &) : ostream &;

  private:
    char* m_msg;
};

#include "array.inc"

#endif

// if given index is less than starting index it's out of bounds
// if index given is equal to or more than the starting index + length
// in bracket operator
// if index is -4 and length is 5, it would go -4, -3, -2, -1, 0.  Need to account for that in the bracket operator