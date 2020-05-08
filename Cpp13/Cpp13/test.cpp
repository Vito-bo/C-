
#include <iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 &&
			((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDays[month];
		}
	}
	Date(int year = 0, int month = 0, int day = 0)
	{
		if (year >= 0
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}

	}


	// ����+=����(d1+=100)
	// d1.operator+=(&d1,100);
	Date& operator+=(int day)
	{
		if (day<0)
		{
			*this -= -day;
			return *this;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			// ������ǰ�µ�����
			_day -= GetMonthDay(_year, _month);
			// �½�1
			++_month;
			// �������1������1
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	/*
	// d1+=100 
	// ��+����ȥʵ��+=
	Date& operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}

	// ����+����(d1+100)
	// d1.operator+(&d1,100);
	Date operator+(int day)
	{
	Date tmp(*this);
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
	tmp._day -= GetMonthDay(tmp._year, tmp._month);
	++tmp._month;
	if (tmp._month == 13)
	{
	tmp._year++;
	tmp._month = 1;
	}
	}
	return tmp;
	}
	*/
	// ʹ��+=����ȥʵ��+
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += -day;
			return *this;
		}
		_day -= day;
		while (_day <= 0) // ע�ⲻ��<
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	
	// ++d1;
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// d1++
	// ����++��������ο������죬����ʹ��ǰ��++
	Date operator++(int)  //Ϊ��������ǰ��++����һ������
	{
		// ����++֮ǰ��ֵ
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// d1<d2
	// ʵ�������ﲻ��inlineҲ���ԣ���Ϊֱ��������ʵ�ֵĺ�����Ĭ�Ͼ���inline
	inline bool operator<(const Date& d)
	{
		if ((_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year = d._year&& _month == d._month&& _day < d._day))
		{
			return true;
		}
		return false;
	}

	// d1==d2
	inline bool operator==(const Date& d)
	{
		return _year == d._year &&_month == d._month&& _day == d._day;
	}
	
	// ������������ʱ�����Ա�������ǿ����ĸ����ԣ�����ĸĶ���С
	// d1<=d2
	inline bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// d1 > d2
	inline bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	// d1>=d2
	inline bool operator>=(const Date& d)
	{
		return !(*this < 0);
	}
	
	// d1 != d2
	inline bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// d1-����
	//Date operator-(int day);
	// ����-����
	int operator-(const Date& d)
	{
		int flag = -1;
		Date min = *this;
		Date max = d;
		if (*this > d)
		{
			flag = 1;
			min = d;
			max = *this;
		}
		int n = 0;
		while (min != max)
		{
			++n;
			++min;
		}
		return n*flag;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test1()
{

	Date d1(2020, 3, 19);
	d1.Print();

	Date d3 = d1 + 100;
	d3.Print();
	d1.Print();


	Date d4 = d1 += 100;
	d4.Print();
	d1.Print();

	d3 -= 100;
	d3.Print();

	//d1 - 50;
	//d1 += 100;
	//d1 -= 50;
	//d1 - d2;

}

void test2()
{
	Date d1(2020, 3, 19);
	//d1 -= -50;
	Date d2(d1);
   // d1.Print();


	Date ret1 = d1++;
	Date ret2 = ++d2;
	d1.Print();
	ret1.Print();
	
	d2.Print();
	ret2.Print();

}

void test3()
{
	Date d1(2020, 3, 21);
	Date d2(2020, 9, 1);
	//cout << d1 - d2 << endl;
	cout << d2-d1<< endl;
}
int main()
{
	test3();
	return 0;
}