
#include <iostream>
using namespace std;

/*

//auto�ؼ���
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a; // ͨ��a�������Զ��Ƶ���c��������int
	auto c = 'a';
	auto d = TestAuto();

	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto e; //ʹ��auto�������ʱ���������г�ʼ��
	return 0;
}

void TestAuto()
{
	auto a = 1, b = 2;
	//auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
}
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	*a = 20;
	*b = 30;
	c = 40;
	return 0;
}
//��ͬһ�ж���������ʱ����Щ������������ͬ�����͡�������������ᱨ��
//��Ϊ������ʵ��ֻ�Ե�һ�����ͽ����Ƶ���Ȼ�����Ƶ����������Ͷ�����������

//auto������Ϊ�����Ĳ���
//void TestAuto(auto a)
{}
//auto����ֱ��������������
void TestAuto()
{
	int a[] = { 1, 2, 3 };
	//auto b[] = { 4��5��6 };
}

//���ڷ�Χ��forѭ��
void TestFor1()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
}
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	return ;
}
int main()
{
	TestFor();

	return 0;
}

//nullptrָ���ֵ
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL); // Ԥ�����Ժ���f(0)
	f((int*)NULL);

	int* p1 = NULL; // C
	int* p2 = nullptr; // C++11�Ƽ���

	// ���ۣ�C++11�Ļ����У�ͳһʹ��nullptr�����ָ��
	return 0;
}

struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Vitobo", "��", 20);
	s.PrintStudentInfo();
	return 0;
}
/
//1.��Ķ���
class className
{
	// ���壺�ɳ�Ա�����ͳ�Ա�������
};
//1.�����Ͷ���ȫ������������
class Person
{
public:
	//��ʾ������Ϣ
	void ShowInfo()
	{
		cout << _name << "-" << _sex << "-" << _age << endl;
	}
public:
	char* _name;
	char* _sex;
	int _age;
};
//2.��������.h�ļ��У���Ķ������.cpp��

class Person
{
public:
	void PrintPersonInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};
// ������Ҫָ��PrintPersonInfo������Person�������
void Person::PrintPersonInfo()
{
	cout << _name << " "<<_gender << " " << _age << endl;
}

class A
{
public:   //����
	int a = 10;
	int b = 20;
protected: //����
	char i = 'm';
private:  //˽��
	int c = 3;
};
int main()
{
	A aa;
	aa.a;
	return 0;
}

class A
{
public:
	void PrintA()
	{
		  cout << _a << endl;
	}
private:
	char _a;
};
// ���м��г�Ա���������г�Ա����
class A1 {
public:
	void f1(){}
private:
	int _a;
};
// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};
// ����ʲô��û��---����
class A3
{};
int main()
{
	A aa;
	cout << sizeof(aa) << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	return 0;
}

class Date
{
public:
	void Display()
	{
		cout << _year << "-" << _month<<"-"<<_day<<endl;
	}
	void setDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1, d2;
	d1.setDate(2008, 8, 8);
	d2.setDate(2020, 8, 8);
	d1.Display();
	d2.Display();
	return 0;
}

class Date
{
public:
	void PrintA()
	{
		cout << this-> _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	Date* p = NULL;
	p->PrintA();
	p->Show();
}
*/