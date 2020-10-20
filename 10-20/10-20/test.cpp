
#include <iostream>
using namespace std;

//��Ͷ���6-

//��ֵ��������غ�const��Ա����

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	Date& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	Date operator+(/*Date* const this,*/int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}

	~Date()
	{}

	// =
	Date& operator=(const Date& d)
	{
		// this��=����������������d��=��������Ҳ�����
		//cout << this << "=" << &d << endl;

		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
		//return d;
	}

	// ǰ��++
	Date& operator++()
	{
		_day++;
		return *this;
	}

	// ����++
	// ��ʹ�� ���+1
	Date operator++(int)
	{
		Date temp(*this);
		_day++;
		return temp;
	}

	Date& operator--()
	{
		_day--;
		return *this;
	}

	// ����++
	// ��ʹ�� ���+1
	Date operator--(int)
	{
		Date temp(*this);
		_day--;
		return temp;
	}

	int _year;
	int _month;
	int _day;
};


Date operator-(const Date& d, int days)
{
	Date temp(d);
	temp._day -= days;
	return temp;
}



/*
int operator+(int left, int right)
{
return left + right;
}
*/


int main()
{
	Date d1(2020, 10, 14);
	Date d2(2020, 10, 15);
	Date d3(2020, 10, 16);

	d1 = d2;
	d1.operator=(d2);

	d1 = d2 = d3; //  ===��d1.operator=(d2.operator=(d3));

	d2 = d1++;  // ����++
	d2 = ++d1;  // ǰ��++

	//d1--;
	d1 = d1;
	Date& d4 = d1;



	d4 = d1;
	if (d1 == d2)
	{
		;
	}

	d2 = d1 + 10;

	int a = 10;
	int b = 20;
	int c = 0;
	c = a + b;

	d2 = d1 - 1;

	a = b;
	a = c;

	a = b = c;

	a++;
	a--;

	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date* operator&()
	{
		cout << this << endl;
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 10, 14);
	//cout << &d1 << endl;
	&d1;

	const Date d2(2020, 10, 15);
	&d2;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ͨ���͵ĳ�Ա����
	// thisָ�������   Date* const this;
	void TestThis()
	{
		//this = nullptr;
		_day++;
	}

	// const���͵ĳ�Ա����
	// const���εĳ�Ա�������ǲ����޸ĳ�Ա������ֵ
	// thisָ������ͣ�const Date* const this

	// ע�⣺һ������ڳ�Ա�����в���Ҫ�޸ĳ�Ա����ʱ����ý��ú������ó�const���͵ĳ�Ա����
	//      ����ڳ�Ա��������Ҫ�޸ĵ�ǰ�����еĳ�Ա����ʱ���ú���һ����������Ϊconst���͵ĳ�Ա����
	//      ����������ʧ��
	bool operator==(const Date& d)const
	{
		// ++_day;  ����ʧ��
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	void PrintDate()const
	{
		// _day++;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	bool operator<(const Date& d)const
	{
		return true;
	}

	// Date* const
	Date* operator&()
	{
		++_day;
		cout << this << endl;
		return this;
	}

	// const Date* const
	const Date* operator&()const
	{
		//++_day;
		cout << this << endl;
		return this;
	}


	void Test1()
	{}

	void Test2()const
	{}

	void TestFuncWithoutConst()
	{
		// TestFuncWithoutConst��thisָ��Ķ���-->�ǿɶ���д��
		Test2(); // Test2: thisָ��Ķ�����ֻ����
	}


	void TestFuncWithConst()const
	{
		// const ���γ�Ա�����������ó�Ա�����е�thisָ��ָ��Ķ����ǲ����޸ĵ�
		// ������ͨ��Ա������thisָ������е������ǿ����޸ĵ�
		// ���const���ͳ�Ա�����п��Ե�����ͨ���͵ĳ�Ա����,�����ڲ����õ���ͨ��Ա�������޸���thisָ��Ķ���
		// ��ô�ⲿconst���ͳ�Ա��������ȫ
		//Test1(/*this*/);
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 10, 14);  // �ɶ���д
	Date d2(2020, 10, 14);
	Date d3(2020, 10, 15);
	const Date d4(2020, 10, 14); // ֻ��

	&d1;
	&d4;

	// ��ͨ���͵Ķ�����Ե���const���͵ĳ�Ա����
	d1.PrintDate();

	if (d1 == d2)
	{
		cout << "��ͬ" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}

	if (d1 == d3)
	{
		cout << "��ͬ" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
	return 0;
}
#endif


// ���캯�����ã���ʼ������--��ʼ������ռ��а����ĳ�Ա������

// ��ʼ���͸�ֵ������

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		// �Ե�ǰ�����еĳ�Ա�����ڽ��и�ֵ
		_year = year;
		_month = month;
		_day = day;
		_day = day;
		// a = 10;
	}

private:
	int _year;
	int _month;
	int _day;

	const int a;
};

int main()
{
	const int a = 10;
	Date d1(2020, 10, 14);

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		, _day(day)
	{
		// �Ե�ǰ�����еĳ�Ա�����ڽ��и�ֵ
		//_year = year;
		//_month = month;
		//_day = day;
		//_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2020, 10, 14);

	return 0;
}
#endif


class Date
{
public:
	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	//�������캯��
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
	//��ֵ���������
	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}
	//����
	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


Date TestDate1(Date d)
{
	Date temp(d);
	temp = d;
	return temp;
}

//���ô��ݣ����÷���
Date& TestDate2(Date& d)
{
	Date temp(d);
	temp = d;
	return d;
}

//ֵ���ݣ�ֵ����
Date TestDate3(Date d)
{
	return d;
}

void TestDate()
{
	Date d1(2020, 10, 14);
	//Date d2(d1);

	//d2 = TestDate1(d1); // ֵ����
	//d2 = TestDate2(d1); // ���ô���

	TestDate3(TestDate3(d1));
}

int main()
{
	TestDate();
	return 0;
}

#endif