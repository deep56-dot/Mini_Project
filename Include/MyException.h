
#ifndef Exception
#define Exception

#include<iostream>
#include "String.h"

using std::string;

class MyException {
	std::string message;

public:
	MyException() : message{ "Something Went Wrong" }{}
	MyException(std::string m) : message{m} {}
	std::string getmessage()  const{
		return message;
	}
};
#endif


