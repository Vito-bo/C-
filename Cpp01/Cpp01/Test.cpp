

#include <iostream>
using namespace std;
#if 0

// ��������
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

short Add(short left, int right)
{
	return left + right;
}

short Add(int left, short right)
{
	return left + right;
}

void TestFunc(int a = 10)
{
	//cout << "void TestFunc(int)" << endl;
}

void TestFunc(int a)
{
	//cout << "void TestFunc(int)" << endl;
}

int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);

	return 0;
}


int main()
{
	int a = 0;
	int& ra = a;
	cout << &a << endl;
	cout << &ra << endl;

	int& b = a;
	cout << &b << endl;
	int& c = b;
	cout << &c << endl;

	//int& d;

	int x = 1;
	c = x; // ��x��ֵ��ֵ��c��������c���x�ı���
	cout << &c << endl;
	cout << &x << endl;

	return 0;
}

int main()
{
	const int a = 10;
	// Ȩ�޷Ŵ� ֻ��->�ɶ���д
	//int& b = a; // ���� a�Լ������ܸı䣬b���ұ��������Ըı䣿->����
	const int& b = a;

	int c = 20;
	int& d = c;
	// Ȩ����С �ɶ���д->ֻ��
	const int& e = c; // ���� c�Լ����Զ����Ըı䣬eֻ�ܶ������ܸı�  ->��
		 
	return 0;
}

int main()
{
	int i = 0;
	double d = i; // ��ʽ���͵�ת��
	const double& rd = i;

	return 0;
}
#endif

//void SwapC(int* pa, int* pb);
void Swap(int& ra, int& rb)
{
	int c = ra;
	ra = rb;
	rb = c;
}

int main()
{
	int a = 0, b = 2;
	Swap(a, b);

	return 0;
}