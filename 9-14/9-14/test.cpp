
#include <iostream>
using namespace std;

//C++��ϰ-����

//1.�����ռ�
//ʹ�������ռ��Ŀ���ǶԱ�ʶ�������ƽ��б��ػ����Ա���������ͻ��������Ⱦ
//�����ռ䶨����һ���µ������������ռ��е��������ݶ������ڸ������ռ���

//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//	namespace M
//	{
//		int c = 30;
//		int d = 40;
//		int Mul(int left, int right)
//		{
//			return left * right;
//		}
//	}
//}
//�����ռ�ʹ�õ����ַ�ʽ
////1.�������ռ����Ƽ��������޶���
//int main()
//{
//	printf("%d\n",N:: a);
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
////3.ʹ��using namespace �����ռ���������
//using namespace N;
//int main()
//{	
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	printf("%d\n", Add(10, 20));
//	return 0;
//}

//3.C++����&���
//int main()
//{
//	cout << "welcome to shanxi" << endl;
//	return 0;
//}
//int main()
//{
//	int a;
//	char c;
//	double d;
//	cin >> a;
//	cin >> c >> d;
//	cout << a << endl;
//	cout << c << " " << d << endl;
//	return 0;
//}

//4.ȱʡ����
//ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ��
//���û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ָ����ʵ��
//void Test1(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Test1(); //û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	return 0;
//}
////ȫȱʡ����
//void Test2(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
////��ȱʡ����
//void Test3(int a, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
//int main()
//{
//	Test2();
//	Test3(1);
//	return 0;
//}
////��ȱʡ������������������θ��������ܼ���Ÿ�
//ȱʡ���������ں��������Ͷ�����ͬʱ����
//��������붨��λ��ͬʱ���֣�ǡ������λ���ṩ��ֵ��ͬ�����������޷�ȷ�����׸����ĸ�ȱʡֵ
//ȱʡֵ�����ǳ�������ȫ�ֱ���

//5.��������
//C++������ͬһ�����������������������Ƶ�ͬ��������
//��Щͬ���������β��б�(���������������� ��˳��)���벻ͬ
//�����ķ������Ϳ�����ͬҲ���Բ���ͬ�������������Ͳ�ͬ�����Գ�Ϊ����������
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//int main()
//{
//	cout << Add(10, 20) << endl;
//	cout << Add(2.3, 5.5) << endl;
//	cout << Add(10l, 20l) << endl;
//	return 0;
//}
//C����û�취֧�ֺ������أ���Ϊͬ������û�취���֡�
//��C++��ͨ���������ι��������֣�ֻҪ������ͬ�����γ��������־Ͳ�һ������֧��������
//��������Ҫ�������ͬ����������ֵû�й�ϵ

////C++�����п�����Ҫ��ĳЩ��������C��������룬�ں���ǰ��extern "C",��˼�Ǹ��߱��������ú�������C���Թ���������
//extern "C" int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	cout << Add(1, 2) << endl;
//	return 0;
//}

//6.����
//���ò��Ƕ���һ���µı��������Ǹ��Ѵ��ڵı���ȡһ������
//��������������ñ��������ڴ�ռ䣬���������õı�����ͬʹ��ͬһ���ڴ�ռ�
//int main()
//{
//	int a = 10;
//	char& ra = a;
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//	return 0;
//}
////�������ͱ��������ʵ����ͬ������

////���õ�����
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//int& ra; //�����ڶ���ʱ�����ʼ��
//	int& ra = a;
//	int& rra = a;//һ�����������ж������
//	//int& rra = b;//����һ������һ��ʵ�壬�ٲ�����������ʵ��
//	printf("%p %p %p\n", &a, &ra, &rra);
//	return 0;
//}

////������
//int main()
//{
//	const int a = 10;
//	//int& ra = a;  //�������aΪ����
//	const int& ra = a;
//	//int& b = 10;//�������bΪ����
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d;//����������Ͳ�ͬ
//	const int& ra = d;
//	return 0;
//}

//���õ�ʹ�ó���
////1.������
//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
////2.������ֵ
//int& Count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}

int& add(int a, int b)
{
	int c = a + b;
	return c;
	//return a + b// ���뱨��  a+b������ֵ �����ʽ ���� û����ֵ��
}
int& Count()
{
	static int n = 0;
	n++;

	return n;
}
int main()
{
	int& ret = add(1, 2);//���ܷ��ؾֲ����������á���Ҫԭ���Ǿֲ��������ں������غ����٣�
	//��˱����ص����þͳ�Ϊ��"����ָ"�����ã���������δ֪״̬��
	int& r = Count();
	cout << r << endl;
	cout << r << endl;
	cout << r << endl;
	return 0;
	//�����������ʱ�����˺���������������ض���δ����ϵͳ�������ʹ�����÷��أ�
	//����� ������ϵͳ�ˣ������ʹ�ô�ֵ���ء�
}
