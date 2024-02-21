#include <iostream>
#include<string>
#include "../Include/Date.h"
//#include "../Include/std::string.h"
#include "../Include/MyException.h"
using Utility::date;

bool date::isDateValid(const date& d1) const {
	if ((d1.m > 0 && d1.m < 13) && (d1.y > 1)) {
		if (d1.d > 0 && d1.d <= DaysInMonth(d1.m,d1.y))
		{
			return true;
		}
	}
	return false;
}
void date::setDate(int dd, int mm, int yy) {
	try {
		if (isDateValid(date{ dd,mm,yy })) {
			cache_valid = false;
			this->d = dd;
			this->m = mm;
			this->y = yy;
		}
		else {
			throw MyException("Date is not valid\n");
		}
	}
	catch (MyException m) {
		std::cout << m.getmessage();
	}
}
int date::DaysInMonth(int m, int y) const {
	switch (m) {
	case 2: {
		if (isLeapYear(y))
			return 29;
		return 28;
	}
	case 4: case 6: case 9: case 11:
		return 30;
	}
	return 31;
}

bool date::isLeapYear(int y) const {
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return true;
	else
		return false;
}

date& date::addYear(int n) {
	cache_valid = false;
	this->y = this->y + n;
	return (*this);
}

date& date::addDay(int n) {
	
	cache_valid = false;
	for (int i = 0; i < n; i++)
	{
		this->d++;
		if(this->d>(date::DaysInMonth(m,y)))
		{
			this->d = 1;
			this->m++;
			if (this->m == 13)
			{
				this->m = 1;
				this->y++;
			}
		}
	}

	return *this;
}

date& date::addMonth(int month) {
	cache_valid = false;
	if (month > 12) {
		this->y = this->y + (month / 12);
		month = month % 12;
	}
	if (this->m + month > 12) {
		this->m = (this->m + month) - 12;
		this->y += 1;
		auto DIM = DaysInMonth(this->m, this->y);
		if (DIM < this->d) {
			auto temp = this->d - DIM;
			this->m++;
			this->d = temp;
		}
	}
	else {
		this->m = this->m + month;
		auto DIM = DaysInMonth(this->m, this->y);
		if (DIM < this->d) {
			auto temp = this->d - DIM;
			this->m++;
			this->d = temp;
		}
	}
	return *this;
}

std::string Utility::date::getstringval() const{
	if (!cache_valid) {
		std::string ans;
		std::string Day = std::to_string(d);
		std::string Month = std::to_string(m);
		std::string Year = std::to_string(y);
		ans = Day + "/" + Month + "/" + Year;
		
		cache = ans;
		cache_valid = true;
		return ans;
	}
	else
		return cache;
}
