
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	//��ʼ���б�
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////ÿ����Ա�����ڳ�ʼ���б�ʱֻ�ܳ���һ��
////���ó�Ա����/const��Ա����/�Զ������ͳ�Ա(����û��Ĭ�Ϲ��캯��)
////���а������ϳ�Ա�������ڳ�ʼ���б�λ�ý��г�ʼ��
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj;     //û��Ĭ�Ϲ��캯��
//	int& _ref;   //����
//	const int _n; //const
//};
////����ʹ�ó�ʼ���б��ʼ����
////�����Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ��
//

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};

//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();
//	return 0;
//}

//explicit�ؼ���
//���캯���������Թ������ʼ�����󣬶��ڵ��������Ĺ��캯��������������ת���Ĺ���
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1(2018);
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
//	d1 = 2019;
//}

//static��Ա
//

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//
//class A
//{
//public:
//
//	void Print()
//	{
//		cout << a << endl;
//	}
//private:
//	//�Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ȱʡֵ
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//
//int main()
//{
//	A a;
//	a.Print();
//
//	return 0;
//}
// ��Ԫ
//��Ԫ�ṩ��һ��ͻ�Ʒ�װ�ķ�ʽ
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}

//��Ԫ��
//��Ԫ������г�Ա��������������һ�������Ԫ������
//�����Է�����һ�����еķǹ��г�Ա
class Date;  //ǰ������
class Time
{
	friend class Date; //����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		//ֱ�ӷ���ʱ����˽�еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};