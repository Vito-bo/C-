
#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int	   _age = 18;		// ����
//};
//
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//
//private:
//	int	   _age = 18;		// ����
//};
//
//struct Student : Person
//{
//public:
//	void f()
//	{
//		_name = "xxx";
//		//_age = 10; �����˽�м̳������Ժ󲻿ɼ�
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	//s._name;
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name; // ����
//	string _sex;  // �Ա�
//	int	_age;	 // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//void main()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}

//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��  �����Ա����(�ض���)����ĳ�Ա
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	return 0;
//}

// �������أ�ͬһ����
// 
// �������У�ͬ����Ա�����������أ�ͬ��������������(��������ֵ�����Բ�ͬ)
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};

//class Person
//{
//public:
//	//Person(const char* name = "peter")
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//// �����༸��Ĭ�ϳ�Ա���������졢�������������졢��ֵ
//class Student : public Person
//{
//public:
//	Student()
//		:Person("xxx")
//	{
//		cout << "Student()" << endl;
//	}
//
//	// s2(s1)
//	Student(const Student& s)
//		:Person(s)
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	// s1 = s3
//	Student& operator=(const Student& s) // �������operator=��������
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//
//
//	~Student()  // Ҳ�������~Person()�������أ��������Ὣ�������������ƴ����destrucator()
//	{
//		//Person::~Person();  ��Ҫ��ʾ���ã���Ϊ���ܱ�֤�ȵ����������ٵ�����������˳��
//		// ������������������ɹ����Զ����ø����
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _id;
//};

// C++98
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{
//public:
//	
//};

// C++11
//class A final
//{
//};
//
//class B : public A
//{
//public:
//
//};

class Person
{
public:
	Person() { ++_count; }
	int _p; // ����
	static int _count; // ͳ���˵ĸ�����
};

int Person::_count = 0;
class Student : public Person
{
public:
	int _stuNum; // ѧ��
	static int _count; // ͳ���˵ĸ�����
};

int Student::_count = 0;


int main()
{
	Person p;
	p._p = 2;
	p._count = 1;


	Student s;
	s._p = 3;
	s._count = 4;

	/*Student s1;
	Student s2(s1);
	Student s3;
	s1 = s3;*/

	//B b;

	return 0;
}

