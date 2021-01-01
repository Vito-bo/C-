#include <iostream>
using namespace std;

#if 0
class A
{
public:
	void Test()
	{
		cout << "A::Test()" << endl;
	}
	void TestFunc()
	{
		Test();
		cout << this << endl;
	}
	int _t;
};

int main()
{
	A a1, a2, a3;
	a1.TestFunc();
	a1.TestFunc();
	a1.TestFunc();

	//A::TestFunc();
	// ��Ա��������Ҫͨ�����������е��ã��ڸó�Ա��������֮ǰ�� 
	//��������Ҫ����ǰ����ĵ�ַͨ��ecx�Ĵ������ݸ���Ա����

	A* pa = &a1;
	pa->TestFunc();
	// ע�⣺pa��A*���͵�ָ�룬����˵pa��������ָ��A���͵Ķ���
	//       ���paָ��û�кϷ�ָ��ʱ��һ�㶼�ǽ���ָ����ΪNullptr
	pa = nullptr;
	pa->TestFunc();

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d;
	d.PrintDate();
	// ��������ʱ���������Զ����ù��캯����������������һЩ��ʶֵ


	Date d1;
	d1.SetDate(2021, 1, 1);
	d1.PrintDate();

	int a = 5;
	int b(a);
	cout << b << endl;
}
// �������û����ʾ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����
// һ���û���ʾ�������������������

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}

	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};


class Date
{
public:
	// �û���ʽ�����˴��в����Ĺ��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

	Time _t;
};


int main()
{
	// Date�����Ѿ���ʽ�����˴������������Ĺ��캯��
	// ��֤�����������᲻�������޲εĹ��캯���أ�

	// ����������ͨ������������������޲ι��캯����
	// ����������ʧ�������û������


	// ���뱨��error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������
	// ��������ʽ�����˹��캯��ʱ�������������������޲ε�Ĭ�Ϲ��캯����

	Date d;  // ����d�����ڼ䣬��������Ҫ�����޲εĹ��캯��
	return 0;
}


class Date
{
public:
	// �޲ι��캯��
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	// ȫȱʡ���캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(202, 1, 1);

	// ���֣������Ե����޲ι��캯��������d2��
	//     Ҳ���Ե���ȫȱʡ�Ĺ��캯��������d2
	// �����˶����ԣ��������ͱ�����
	//Date d2;
	return 0;
}
#endif

#if 0
// ��������
typedef int DataType;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_arr = (DataType*)malloc(sizeof(DataType)*capacity);
		_capacity = capacity;
		_size = 0;
	}

	//��������
	~SeqList()
	{
		if (_arr)
		{
			free(_arr);
			_arr = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(DataType x)
	{

	}
private:
	DataType* _arr;
	size_t _capacity;
	size_t _size;
};

class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
void Test()
{
	Person p;
}
int main()
{
	Test();

	String s("nihao shjie");
}
#endif 

#if 0
// �������캯��
class Date
{
public:
	// ��Ա����������ʵ�֣��������п��ܻὫ�䵱����������������
	Date(int year = 1000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&)" << endl;
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
int main()
{
	Date d1;
	Date d2(2021, 1, 1);
	Date d3(d2);

	return 0;
}



// ע�⣺��������漰����Դ����ʱ���������Ҫ��ʾ�ṩ��������
//		�����������н��������Դ�ͷŵ�������ᷢ����Դй©

// ���������ɵ�Ĭ�Ͽ������캯���ǰ���ǳ������ʽʵ�ֵġ�
// ǳ��������һ�������е�����ԭ�ⲻ���Ŀ�������һ��������
// ��������������ͬһ����Դ�������ڶ�������ʱ�÷���Դ���ͷŶ�ζ����´������

// ע�⣺һ����������漰����Դ����ʱ���������캯���Ǳ���Ҫʵ�ֵ�

class String{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}


	// String��û��ʵ���Լ��Ŀ������캯�����������������һ��
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1("hello world");
	String s2(s1);
}


int main()
{
	TestString();
	return 0;
}
#endif

#if 0
// ��ֵ���������
class Date
{
public:
	// ��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);
	Date d3(2020, 10, 13);

	// ���ø�ֵ��������غ���
	// ���һ����û����ʽʵ�ָ�ֵ��������غ������������������һ��Ĭ�ϵ�
	// ��ɶ���֮��ĸ�ֵ����
	d1 = d3;

	int a = 10;
	int b = 20;
	a = b;

	return 0;
}


// ע�⣺��������漰����Դ����ʱ����ֵ�������������Ҫ��ʽʵ�ֳ���
//	���������ɵĸ�ֵ����������ǰ���ǳ�����ķ�ʽʵ�ֵ�
// ��������漰����Դ����ʱ���ᵼ�����º����1.ǳ���������һ����Դ�ͷŶ��������������2.s1ԭ���Ŀռ䶪ʧ��-�ڴ�й©

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}
	
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// �����Զ������ͣ���������֪����ν�����Ӧ������Ĳ���
	// �����Ҫ�Ը�������������أ��൱�ڸ��߱�������Ը������͵Ķ������ȥ�������������
	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
	}
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	
	Date& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	Date operator+(int days)
	{
		Date tmp(*this);
		tmp._day += days;
		return tmp;
	}

	Date& operator=(const Date& d)
	{
		// this��=����������������d��=��������Ҳ�����
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// ǰ��++
	Date& operator++()
	{
		_day++;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date tmp(*this);
		_day++;
		return tmp;
	}

	// ǰ��--
	Date& operator--()
	{
		_day--;
		return *this;
	}

	// ����--
	// ��ʹ�ã���-1
	Date operator--(int)
	{
		Date tmp(*this);
		_day--;
		return tmp;
	}

	Date operator-(int days)
	{
		Date temp(*this);
		temp._day -= days;
		return temp;
	}

	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;

};
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
	d4--;


	return 0;
}
#endif


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
	// const���εĳ�Ա�����ǲ��ܱ��޸ĳ�Ա������ֵ��
	// thisָ������ͣ�const Date* const this
	//

	// ע�⣺һ�������Ա�����в���Ҫ�޸ĳ�Ա����ʱ����ý��ú������ó�const���͵ĳ�Ա����
	//	����ڳ�Ա��������Ҫ�޸ĵ�ǰ�����еĳ�Ա����ʱ���ú���һ����������Ϊconst���͵ĳ�Ա�������������ʧ��
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
	int a = 100;
	int b = 200;
	int c = 300;
	int d = 400;
	int* p1 = &a;
	p1 = &b;

	const int* p2 = &b;
	p2 = &a;
	*p2 = 2;

	int const* p3 = &c;
	p3 = &a;
	*p3 = 3;

	const int* const p4 = &d;
	p4 = &a;
	*p4 = 4;

	return 0;
}