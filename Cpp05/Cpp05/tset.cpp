
#include <iostream>
using namespace std;

//
//class Sum
//{
//public:
//	Sum()
//	{
//		_sum += _i;
//		++_i;
//	}
//	//��̬��Ա������ʼ��
//	static void Init()
//	{
//		_i = 1;
//		_sum = 0;
//	}
//	static int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum a[n]; //c99 �䳤����
//		Sum::Init();
//		Sum* p = new Sum[n];
//		return Sum::GetSum();
//	}
//};

//int main()
//{
//	// һ��int
//	int* p1 = (int*)malloc(sizeof(int)); //C
//	int* p2 = new int; //C++
//
//	free(p1);
//	p1 = nullptr;
//	delete p2;
//	p2 = nullptr;
//
//	//10��int�͵�����
//	int* p3 = (int*)malloc(sizeof(int)* 10);
//	int* p4 = new int[10];
//
//	free(p3);
//	delete[] p4;
//
//	//����һ��int���󣬲��ҳ�ʼ����10
//	int* p5 = new int(10);
//	delete p5;
//
//
//
//	return 0;
//}

//void Test()
//{
//	//��̬����һ��int���͵Ŀռ�
//	int* p1 = new int;
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* p2 = new int(10);
//	//��̬����10��int���͵Ŀռ�
//	int* p3 = new int[10];
//
//	//new delete������
//	delete p1;
//	delete p2;
//	delete[] p3;
//}

//new��delete�����Զ�������
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//
//void Test1()
//{
//	// ���뵥��Test���͵Ŀռ�
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	// ����10��Test���͵Ŀռ�
//	Test* p2 = (Test*)malloc(sizeof(Test)*10);
//	free(p2);
//
//}
//
//void Test2()
//{
//	// ���뵥��Test���͵Ŀռ�
//	Test* p1 = new Test;
//	delete p1;
//
//	// ����10��Test���͵Ŀռ�
//	Test* p2 = new Test[10];
//	delete[] p2;
//}
//
//int main()
//{
////	Test1();
//	Test2();
//	
//	return 0;
//}

/*
operator new���ú���ʵ��ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�ʧ�ܣ�
����ִ�п� �䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬�������쳣��
*/
