
#include <iostream>
using namespace std;

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
////struct A{ int a[10000]; };
//
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	int* pa = &a;
//
//	return 0;
//}


//inline int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//// C������ν��С����Ƶ�����ÿ�����-���꺯��
//// C++��ν��С����Ƶ�����ÿ���? -��inline����
//
//int main()
//{
//	Add(1, 2);
//
//	return 0;
//}

#include <unordered_map>

//int main()
//{
//	int a = 10;
//	int b = a;
//	
//	auto c = a; // ͨ��a�������Զ��Ƶ���c��������int
//	cout << typeid(c).name() << endl;
//
//	std::unordered_map<std::string, std::string> m;
//	// auto�������õ����֣��Ժ���бȽϸ��ӵ����Ͷ��壬ʹ��auto�᷽��Щ
//	//std::unordered_map<std::string, std::string>::iterator it = m.begin();
//	auto it = m.begin();
//
//	return 0;
//}


//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		array[i] *= 2;
//	}
//
//	// ��д���ϸ����  ->���Ը��µ����ƣ����÷�
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//
//	// ��Χfor
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

//#ifdef __cplusplus
//#define NULL    0
//#else

//int main()
//{
//	f(0);
//	f(NULL); // Ԥ�����Ժ���f(0)
//	f(nullptr);
//
//	int* p1 = NULL; // C
//	int* p2 = nullptr; // C++11�Ƽ���
//
//	// ���ۣ�C++11�Ļ����У�ͳһʹ��nullptr�����ָ��
//
//	return 0;
//}
