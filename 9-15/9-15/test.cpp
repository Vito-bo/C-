
#include <iostream>
using namespace std;
#include <time.h>

////��ֵ��������Ч�ʱȽ�
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//
//void TestFunc2(A& a){}
//
//void TestRefAndValue()
//{
//	A a;
//	//��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; i++){
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//
//	//��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; i++){
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//
//	//�ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl; //9
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//0 
//}
//��ֵ��Ϊ�������߷���ֵ���ͣ��ڴ�ֵ�ͷ���ֵ�ڼ䣬��������ֱ�Ӵ���ʵ�λ��߽���������ֱ�ӷ���
//���Ǵ���ʵ�λ��߷��ر�����һ����ʱ�Ŀ����������ֵ��Ϊ�������߷���ֵ���ͣ�Ч���Ƿǳ����µ�

////ֵ�����õ���Ϊ����ֵ���͵����ܱȽ�
//struct A{ int a[10000]; };
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
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;//191
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;//1
//}
////��ֵ����������Ϊ�����Լ�����ֵ������Ч�����ܴ�
////��ֵ����һ���������һ����ʱ���󣬶����õ����ǵ��ò�������
//int main()
//{
//	//TestRefAndValue();
//	TestReturnByRefOrValue();
//	return 0;
//}

////���ú�ָ�������
////�������﷨�����Ͼ���һ����������������ʵ�干��ͬһ��ռ�
////�ڵײ�ʵ����ʵ�����пռ�ģ���Ϊ�����ǰ���ָ�뷽ʽ��ʵ�ֵ�
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

////��������-inline���εĺ���
////C++�������ں����������������ĵط�չ��
//inline int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	int ret = 0;
//	ret = Add(2, 3);
//	return 0;
//}

////auto�ؼ���:auto�����ı��������ɱ������ڱ������ڱ���ʱ�Ƶ�����
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	return 0;
//}

////auto��ʹ��ϸ��
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//���ڷ�Χforѭ��
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	return 0;
}


