#include <iostream>
using namespace std;

////1.������ģ�����
//namespace bo
//{
//	//����һ��ģ�����͵ľ�̬����
//	template<class T, size_t N=10>
//	class array
//	{
//	public:
//		T& operator[](size_t index){
//			return _array[index];
//		}
//		const T& operator[](size_t index)const{
//			return _array[index];
//		}
//		size_t size()const{
//			return _size;
//		}
//		bool empty()const{
//			return 0 == _size;
//		}
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
////ģ����ػ�
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//
////����ģ���ػ�
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
////һ��������������ģ���������ܴ�����ߴ�����������ͣ�Ϊ��ʵ�ּ�ͨ�����ǽ��ú���ֱ�Ӹ���
//bool IsEqual(char* left, char* right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}

////2.��ģ����ػ�-ȫ�ػ�
////ȫ�ػ��ǽ�ģ������б������еĲ�����ȷ����
//template<class T1, class T2>
//class Data
//{
//public:
//	Data(){
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}

//2.2ƫ�ػ�
//�κζ�ģ�������һ�������������Ƶ��ػ��汾��
// ���ڶ��������ػ�Ϊint
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//��������ƫ�ػ�Ϊָ������
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//��������ƫ�ػ�Ϊ��������
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};
void test2()
{
	Data<double, int> d1; // �����ػ���int�汾
	Data<int, double> d2; // ���û�����ģ��
	Data<int *, int*> d3; // �����ػ���ָ��汾
	Data<int&, int&> d4(1, 2); // �����ػ���ָ��汾
}





int main()
{
	//Test1();
	return 0;
}