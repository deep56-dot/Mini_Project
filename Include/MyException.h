
#ifndef Exception
#define Exception

#include<iostream>
#include "String.h"

using Type::String;

class MyException {
	String message;

public:
	MyException() : message{ "Something Went Wrong" }{}
	MyException(String m) : message{m} {}
	String getmessage()  const{
		return message;
	}
};
#endif


