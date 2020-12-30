
#include <iostream>
using namespace std;


// ����ѧϰ
int& Count()
{
	static int n = 0;
	n++;
	return n;
}

int main()
{
	Count();
	return 0;
}


#if 0
#include <time.h>
struct A{
	int a[100000];
};

void TestFunc1(A a){}
void TestFunc2(A* a){}
void TestFunc3(A& a){}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(&a);
	size_t end2 = clock();

	// ��������Ϊ��������
	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc3(a);
	size_t end3 = clock();


	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc1(A*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	int a = 10;        //ra����a�ı���
	const int& ra = a; //ra��a�ڵײ�ʹ�õ���ͬһ���ڴ�ռ�

	// ra = 100; ����ֱ��ͨ��ra��=�޸�a�ռ��д洢�����ݣ���Ϊ��ra��const����
	a = 200;           //�޸�a,raҲ���޸���
	return 0;
}


int main()
{
	double d = 12.34;
	const int& rd = d;

	d = 56.78;
	cout << rd << endl; //12
	//d��rd�ĵ�ַ��һ����rd������d�ı�������rd���õĲ���d
	return 0;
}


int& Add(int left, int right)
{
	int ret = left + right;
	return ret;
}
int main()
{
	int& result = Add(1, 2);

	Add(3, 4);//result=7
	Add(5, 6);//result=11
	//Add�������н���������û������ջ֡�������µ��������ݣ�
	//��ˣ�result��ret�ı�����result���Կ����ռ��е��������ݡ�
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	int& ra = a;
	int b = 20;
	ra = b;

	return 0;
}

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
// ����������Ϊ�������β�
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

/// ���飺�������ͨ���β����ı��ⲿʵ�������£�������const����������Ϊ�β�
void Print(const int& r)
{
	cout << r << endl;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b); // ����int*
	
	Print(a);
	Print(b);

	Swap(a, b);  // ����int&
	Print(a);
	Print(b);

	return 0;
}



// ��C++�У��������������ַ�ʽ����ֵ������ַ��������
// ��ֵ���β���ʵ�ε�һ�ݿ��������ε�Ч�ʵͣ�����ͨ���ı��βζ��ı��ⲿ��ʵ�Ρ�
// ����ַ���βα������ʵ�εĵ�ַ������Ч�ʸߣ�����ͨ���βθı��ⲿ��ʵ�Ρ�
// �����ã��β�ʵ����ʵ�εı���������Ч�ʸߣ�����ͨ���βθı��ⲿ��ʵ��--���Դﵽ��ָ�����Ƶ�Ч�������ұ�ָ������Ը��߸���ȫ


// ��ֵ�ʹ�����
#include <time.h>
struct A{
	int a[100000];
};

void TestFunc1(A a){}
void TestFunc2(A* a){}
void TestFunc3(A& a){}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(&a);
	size_t end2 = clock();

	// ��������Ϊ��������
	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc3(a);
	size_t end3 = clock();


	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc1(A*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

void Test()
{
	const int a = 10;
	//int& ra = a;     //�������aΪ����
	const int& ra = a; 

	//int& b = 10;      //�������bΪ����
	const int& b = 10;

	double d = 12.34;
	//int& rd = d;        //����ʱ�������Ͳ�ͬ
	const int& rd = d;
}
int main()
{

	int a = 10;
	int& ra = a;
	//int&& rra = ra;

	TestRefAndValue();
	return 0;
}
#endif