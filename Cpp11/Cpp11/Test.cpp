

#include <iostream>
using namespace std;
//����������ͳ�ʼ����->���캯��
//	Date d1(2020, 3, 12);
//	d1.Print();
//
//	Date d2(2020, 3, 13);
//	d2.Print();
//
//	//Date d3();  // ����d3û�б��������
//	Date d3; 
//	d3.Print();
//
//	// ���캯��ֻ���ڶ������ʱ���Զ�����һ��,������Ҫ�޸�Init
//	d3.Init(2020, 3, 14);
//	d3.Print();
//
//	Date d4(2020);
//	d4.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	// �޲κ�3�������޷���ȫȱʡ��3���������캯������
//	/*Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//
//	Date()
//	{
//	_year = 0;
//	_month = 1;
//	_day = 1;
//	}*/
//
//	// ȫȱʡ�Ĺ��캯�� �Ƽ���д��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// û��д���캯����������������һ��Ĭ�Ϲ��캯��
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// �ֱ����4�����صĹ��캯�� �� �Ƽ�дȫȱʡ�Ĺ��캯��
//	Date d1;
//	Date d2(2020);
//	Date d3(2020, 1);
//	Date d4(2020, 2, 2);
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();
//
//	Date d1;  // ����Ĭ�ϵĹ��캯�� ->C++�в��ô���ȥ���ù��캯������Ĭ�Ϲ��캯��
//	d1.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()Ĭ�Ϲ��캯��" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//	/*Time(int hour)
//	{
//	_hour = hour;
//	_minute = 0;
//	_second = 0;
//	}*/
//
//	void Print()
//	{
//		cout << _hour << ":" << _minute << ":" << _second << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		_t.Print();
//	}
//
//	// ���ǲ�ʵ�ֹ��캯����ʱ�򣬱�����������һ��Ĭ�Ϲ��캯����
//	// �������Ͳ���ʼ��
//	// �Զ������ͣ��������(Time)��Ĭ�Ϲ��캯�����г�ʼ��
//private:
//	// ��������/��������
//	int _year;
//	int _month;
//	int _day;
//
//	// class��struct��������Զ�������
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}



//class Date
//{
//public:
//	// ȫȱʡ�Ĺ��캯�� �Ƽ���д��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//~Date()
//	//{
//	//	// Date��û����Դ��Ҫ������������������ʲô������д
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int)*n);
//		_size = 0;
//		_capacity = n;
//	}
//
//	// Date��д������û���⣬�������ɾͿ���
//	// Stack��д�����������⣬���ڴ�й©
//	//~Stack()
//	//{
//	//	// Stack����������������Դ��Ҫ����
//	//	free(_a);
//	//	_size = _capacity = 0;
//	//	_a = nullptr;
//	//}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Date d1; // �����������������d1�������٣�d1��������ʱϵͳ��ɡ�����������ɵ�����������
//	d1.Print();
//
//	Stack st; //Stack st(100);
//	// Push/Pop
//
//	// struct Stack st
//	// Init     �Ա�  ���캯��
//	// Destory  �Ա�  ��������
//	// ��������Init��Destory   �Ա� �Զ����ã����������˵�����
//	// C++��ʹ�ù��캯�������������������Щ����
//
//	return 0;
//}
