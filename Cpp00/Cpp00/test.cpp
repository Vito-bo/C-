
#if 0
#include <stdio.h>

//1.�����ռ�Ķ���

//�����ռ���Զ�����������Զ��庯����Ҳ����Ƕ��
//�����ռ����������ͻ��������Ⱦ

//1.��ͨ�������ռ�
//namespace�ؼ��� ���������ռ�
namespace N1 //N1Ϊ�����ռ������
{
	//�����ռ��е�����,���Զ����������
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//2.�����ռ��Ƕ�׶���
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
		int Sub(int x, int y)
		{
			return x + y;
		}
	}
}

//3.ͬһ��������������ڶ����ͬ���Ƶ������ռ�
//����������ϳ�ͬһ�������ռ���
namespace N1
{
	int Mul(int left, int right)
	{
		return left* right;
	}
}
//һ�������ռ�Ͷ�����һ���µ�������
//�����ռ��е��������ݶ������ڸ������ռ���


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


//�����ռ������ʹ�÷���
//1.�������ռ����Ƽ��������޶���
//int main()
//{
//	printf("%d\n", n::a);
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
//3.ʹ��using namespace�����ռ���������
using namespace N;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	printf("%d\n",Add(10, 20));
	return 0;
}

//3.C++������&���
#include <iostream>
using namespace std;// std C++��׼��������ռ�
int main()
{
	cout << "Hello World" << endl;
	//cout��׼���������̨��
	//cin ��׼���루���̣�
	
	int a = 1;
	double d = 1.1;
	//ָ����ʽ�������
	//printf("%d��%.lf\n", a,d);
	// �Զ�ʶ������
	cout << a << "," << d << endl;
	return 0;
}

//3.1 C++����
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	//C��������
	//scanf("%d", &a);
	//printf("%d\n");

	double b;
	char c;
	cin >> b >> c;
	cout << b << " " << c << endl;
	return 0;
}

//4.ȱʡ����
//ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ
//�ڵ��õ�ʱ�����û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ָ����ʵ��
#include <iostream>
using namespace std;

void Test(int a = 0)
{
	cout << a << endl;
}
int main()
{
	Test();  //û�д���ʱ��ʹ�ò�����Ĭ��ֵ
	Test(2); //����ʱ��ʹ��ָ����ʵ��
	return 0;
}
#endif


#include <iostream>
using namespace std; 
// ȫȱʡ����
void Test(int a=10, int b = 20, int c=30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
// ��ȱʡ����
void Test1(int a, int b = 10, int c = 30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
int main()
{
	Test1(1);
	Test1(1, 2);
	Test1(1, 2, 3);

	return 0;
}
//1.��ȱʡ������������������������������ܼ���Ÿ�
//2.ȱʡ���������ں��������Ͷ�����ͬʱ����
//3.ȱʡֵ�����ǳ�������ȫ�ֱ���
//4.C���Բ�֧��ȱʡ��������������֧�֣�

