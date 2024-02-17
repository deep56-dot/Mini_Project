#ifndef date1
#define date1
#include "String.h"
using Type::String;
namespace Utility {
	class date {
	private:
		int d;
		int m;
		int y;
		bool isLeapYear(int) const;
		bool isDateValid(const date&) const;
		int DaysInMonth(int, int) const;
		mutable bool cache_valid = false;
		mutable String cache{};
	public:
		date(int dd=1, int mm=1, int yy=1970) : d{ dd }, m{ mm }, y{ yy } {}
		void setDate(int , int , int );
		int getDay() const { return d; };
		int getMonth() const { return m; };
		int getYear() const { return y; };

		date& addMonth(int);
		date& addDay(int);
		date& addYear(int);
		String getstringval() const;
		
	};
}

#endif
