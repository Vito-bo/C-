
#include <iostream>
#include <assert.h>
using namespace std;


////1.���ͱ��
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//...
//���ͱ�̣���д�������޹ص�ͨ�ô��룬�Ǵ��븴�õ�һ���ֶΡ�
//ģ���Ƿ��ͱ�̵Ļ���

//1.����ģ��

//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
////ע�⣺typename����������ģ������ؼ��֣�Ҳ����ʹ��class(�мǣ�����ʹ��struct����class)
//

//int main()
//{
//	//int i1 = 10;
//	//int i2 = 20;
//
//	//char a = '0';
//	//char b = '9';
//
//	double d1 = 2.0;
//	double d2 = 5.0;
//
//	//Swap(i1, i2);
//	//Swap(a, b);
//	Swap(d1, d2);
//
//
//	return 0;
//}

//��ʽʵ����

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
////int main()
////{
////	int a1 = 10, a2 = 20;
////	double d1 = 10.0, d2 = 20.0;
////	Add(a1, a2);
////	Add(d1, d2);
////	/*
////	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
////	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
////	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
////	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
////	Add(a1, d1);
////	*/
////	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
////	Add(a1, (int)d1);
////	return 0;
////}
//
////��ʽʵ�������ں��������<>��ָ��ģ�������ʵ������
//
//int main()
//{
//	int a = 10;
//	double d = 20.0;
//	//��ʽʵ����
//	Add<int>(a, d);
//	return 0;
//}

//ģ�������ƥ��ԭ��
// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//
//	Add(1, 2.0);
//}
//ģ�庯���������Զ�����ת��������ͨ�������Խ����Զ�����ת��

//��ģ��
//��̬˳���
template<class T>
class Vector
{
	Vector(size_t capacity = 10)
	: _pData(new T[capacity])
	, _size(0)
	, _capacity(capacity)
	{}

	//ʹ������������ʾ�������������������ⶨ��
	~Vector();

	void PushBack(const T& data);
	void PopBack();
	//...
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
//ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Vector<T>::Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}
