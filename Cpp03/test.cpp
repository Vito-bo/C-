
#include <iostream>
using namespace std;
/*
//1.��ͨ�������ռ�
namespace N1 //N1Ϊ�����ռ�
{
	//�����ռ��е����ݼȿ��Զ��������Ҳ���Զ��庯��
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//2.�����ռ����Ƕ��
namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}

	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

//3.ͬһ��������������ڶ����ͬ���Ƶ������ռ䣬����������ϳ�ͬһ�������ռ��С�
namespace N1
{
	int Mul(int left, int right)
	{
		return left*right;
	}
}
// һ�������ռ�Ͷ�����һ���µ�������
// �����ռ��е��������ݶ������ڸ������ռ���

//2.�����ռ��ʹ��
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
//�����ռ������ʹ�÷�ʽ
//1.�������ռ����Ƽ��������޶���
//int main()
//{
//	//printf("%d\n", a);  //��������޷�ʶ��a
//	printf("%d\n", N::a); 
//	return 0;
//}

//2.ʹ��using�������ռ��г�Ա����
//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//3.ʹ��using namespace �����ռ���������
using namespace N;
int main()
{
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", Add(10,20));
	return 0;
}

//3.C++����&���

//cout��׼���������̨��cin��׼���루���̣�
//�������<iostream>ͷ�ļ��Լ�std��׼�����ռ�
using namespace std;
int main()
{
	cout << "Hello World!" << endl;
	return 0;
}

//2.ʹ��C++������������㣬����Ҫ�������ݸ�ʽ����
using namespace std;
int main()
{
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;

	cout << a << endl;
	cout << b << " " << c << endl;
	return 0;
}

//4.ȱʡ����
//ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ
//�ڵ��øú���ʱ�����û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ָ����ʵ��

using namespace std;
void Test(int a = 0)
{
	cout << a << endl;
}
int main()
{
	Test();  //û�д���ʱ��ʹ�ò�����Ĭ��ֵ
	Test(10);//����ʱ��ʹ��ָ����ʵ��
	return 0;
}

//4.1ȱʡ��������
//ȫȱʡ����
using namespace std;
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//��ȱʡ����
void TestFunc1(int a, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	TestFunc();
	TestFunc(1);
	TestFunc(1,2);
	TestFunc(1, 2, 3);
	TestFunc1(1, 2);
	return 0;
}
//ȫȱʡ���ǲ���ȫ����ȱʡֵ����ȱʡ��ȱʡ���ֵ�ֵ
//1.��ȱʡ������������������������������ܼ���Ÿ�
//2.ȱʡ���������ں��������Ͷ�����ͬʱ����
//3.ȱʡֵ�����ǳ�������ȫ�ֱ���
//C���Բ�֧�֣���������֧�֣�

//5.��������
//C++������ͬһ�����������������������Ƶ�ͬ��������
//��Щͬ���������β��б���������/����/˳�򣩱��벻ͬ

using namespace std;
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	int a = Add(10, 20);
	double b = Add(10.0, 20.0);
	long c =  Add(10L, 20L);
	cout << a << " " << b << " " << c << endl;
	return 0;
}

extern "C" int Add(int left, int right);
int main()
{
	Add(10, 20);
	return 0;
}

//6.����
//���ò����¶���һ�����������Ǹ��Ѵ��ڱ���ȡһ������
//����������Ϊ���ñ��������ڴ�ռ䣬���������õı�������ͬһ���ڴ�
//�������ͱ��������ʵ����ͬ������
//һ�����������ж������
int main()
{
	int a = 10;
	//int& ra; //������������ڶ���ʱ�����ʼ��
	int& ra = a; 
	int& rra = a;
	printf("%p\n", &a);
	printf("%p\n", &ra);
	printf("%p\n", &rra);
	return 0;
}

//6.1������
int main()
{
	const int a = 10;
	// Ȩ�޷Ŵ�ֻ����>�ɶ���д
	//int& ra = a;//aΪ��������ֵ���ܸı䣬b��a�ı���Ҳ�����Ըı�
	const int& ra = a;
	//int& b = 10;
	//Ȩ����С���ɶ���д-��ֻ��
	const int& c = 10;//cֻ�ܶ������ܸı�
	double d = 12.34;
	int& rd = d;
	const int& rd = d;

}


//6.2 ����������
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
int main()
{
	int a = 2, b = 3;
	Swap(a, b);
	return 0;
}

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int& ret = Add(1, 2);
	cout << "Add(1, 2) is :" << ret << endl;
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}


#include <time.h>
//struct A{ int a[10000]; };

A a;
// ֵ����
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2(){ return a; }

void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main()
{
	TestReturnByRefOrValue();

	return 0;
}

int main()
{
	int a = 10;

	int& ra = a;
	int* pa = &a;

	return 0;
}


inline int Add(int a, int b)
{
	int c = a + b;
	return c;
}

// C������ν��С����Ƶ�����ÿ�����-���꺯��
// C++��ν��С����Ƶ�����ÿ���? -��inline����

int main()
{
	Add(1, 2);

	return 0;
}

#include <unordered_map>

int main()
{
	int a = 10;
	int b = a;
	
	auto c = a; // ͨ��a�������Զ��Ƶ���c��������int
	cout << typeid(c).name() << endl;

	std::unordered_map<std::string, std::string> m;
	// auto�������õ����֣��Ժ���бȽϸ��ӵ����Ͷ��壬ʹ��auto�᷽��Щ
	//std::unordered_map<std::string, std::string>::iterator it = m.begin();
	auto it = m.begin();

	return 0;
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

	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		array[i] *= 2;
	}

	// ��д���ϸ����  ->���Ը��µ����ƣ����÷�
	for (auto& e : array)
	{
		e *= 2;
	}

	// ��Χfor
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
}
void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

#ifdef __cplusplus
#define NULL    0
#else

int main()
{
	f(0);
	f(NULL); // Ԥ�����Ժ���f(0)
	f(nullptr);

	int* p1 = NULL; // C
	int* p2 = nullptr; // C++11�Ƽ���

	// ���ۣ�C++11�Ļ����У�ͳһʹ��nullptr�����ָ��

	return 0;
}
*/




