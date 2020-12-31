
#include <iostream>
using namespace std;

// ��Ͷ���
// �ࣺ�ǶԶ���������������
// ��������ʵ�����е�ʵ��
#if 0
// ��C++�У�struct������������;Ϳ��Կ�����һ������
struct Student
{
	// �ṹ���еı���
	char _name[20];
	char _gender[3];
	int _age;

	// �ṹ���еĺ���
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};

int main()
{
	// ��C�����еķ�ʽ
	struct Student s1;
	s1._age = 18;

	// ��C++��
	Student s2;
	s2.InitStudent("BOBO", "MAN", 22);
	s2.SetAge(20);
	s2.PrintStudent();
	return 0;
}


// ��C++�У�����һ����ʹ��class�ؼ���
// ��ʽ1������Ա���������������ж���
class Student
{
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;

public:
	// ��Ա����
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// ע�⣺��Ա������������ڽ��ж��壬��Ա�������ܻᱻ���������������������Դ�
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};
int main()
{
	// Student�����������Խ��俴����ѧ����һ��Ⱥ��
	// s��Student��������Ķ���
	Student s;

	s.InitStudent("bobo", "nan", 20);
	s.PrintStudent();

	return 0;
}


// ��ʽ2����Ա��������������������ж���
// ��Ա������֮ǰ�������::�������ú����������ĳ�Ա����
// ���û�мӣ����൱����ȫ���������ж�����һ������

class Person
{
public:
	void Eat();
	void Sleep();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

void Person::Eat()
{
	cout << "������" << endl;
}
void Person::Sleep()
{
	cout << "��" << endl;
}


// ��μ���һ����/����Ĵ�С��
class  Student
{
public:
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	// ��Ա����
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// ע�⣺��Ա������������ڲ�����ж��壬��Ա�������ܻᱻ���������������������Դ�
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 18);
	cout << sizeof(s1) << endl;
	return 0;
}


class A
{
public:
	void SetA(int a)
	{
		_a = a;
	}

private:
	int _a;
};


class B
{
public:
	void TestB()
	{}
};


class C
{};

// �յĽṹ���Ƕ����أ�
// ��������C++�У���struct��������Ľṹ�������
// ����:ʵ��ÿ��ʵ�����ڴ��ж���һ����һ�޶��ĵ�ַ���������������һ�����������ļ�һ���ֽڣ�
//����������ʵ���������ڴ�õ��˶�һ�޶��ĵ�ַ�����Կ�����ռ���ڴ��С��1���ֽڡ�
struct D
{};

struct AA
{
	int a;
	char b;
	double c;
	char d;
};


int main()
{
	// ���ۣ���һ����Ĵ�С--->ֻ�轫����"��Ա����"��������ע���ڴ����
	cout << sizeof(A) << endl;   // 4
	cout << sizeof(B) << endl;   // 1
	cout << sizeof(C) << endl;   // 1

	cout << sizeof(D) << endl;

	cout << sizeof(AA) << endl;
	return 0;
}
#endif

class Student
{
public:
	char _name[20];
	char _gender[20];
	int _age;

public:
	// ��Ա����
	// �������ú���������������ʵ������4��
	// ����һ�������ǣ�������thisָ��
	void InitStudent(char name[], char gender[], int age)
	{
		// ���ܸ�thisָ�������и�ֵ��������* const
		//this = nullptr;

		cout << this << endl;

		// ����thisָ�룬��Ա������֪���������ڲ����Ǹ�����
		// ע�⣺�Գ�Ա�����Ĳ�������ͨ��thisָ�������еġ�
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	//
};
int main()
{

	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	cout << sizeof(s1) << endl;

	return 0;
}

