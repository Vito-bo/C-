#include <iostream>
#include <assert.h>
using namespace std;

////ͨ�õĽ�������
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

//���ͱ�̣���д�������޹ص�ͨ�ô��룬�Ǵ��븴�õ�һ���ֶΡ�
//ģ�巺�ͱ�̵Ļ���

////����ģ��
////template<typename T>
//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	double d1 = 2.0;
//	double d2 = 5.0;
//	Swap(d1, d2);
//	return 0;
//}

////��ʽʵ�������ñ���������ʵ������ģ�������ʵ������
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 10;
//	double d1 = 10.0, d2 = 20.0;
//	cout<<Add(a1, a2)<<endl;
//	cout<<Add(d1, d2)<<endl;
//	
//	//cout << Add(a1, d1) << endl;
//	//�û�ǿ��ת��
//	cout << Add(a1, (int)d1) << endl;
//
//	return 0;
//}

////��ʽʵ�������ں��������<>��ָ��������ʵ������
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a = 10;
//	double d = 20.0;
//	cout << Add<int>(a, d) << endl;
//
//
//	return 0;
//}

////ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
////ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2); //���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); //���ñ������ػ���Add����
//
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add��
//
//}

namespace bit_c
{
	// ˳��� -- ���Զ�̬����������
	// C���Զ����˳���
	// ���ݺͷ����Ƿֿ�����
	// ����1�������ǿ��Ա����ĵ�  CPP��ν��->��ķ�װ �Ȱ����ݺͷ����ŵ�һ��ͨ�������޶�������һ��
	// ����2���������࣬Ҫͬʱ����SeqList seq1,Ҫ��int; SeqList seq2,��double.
	//        �������2��C����ȥ���������ʵ�֣������߼�һ�������Ͳ�һ��  CPP��ν��-����ģ��
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType*   _a;
		size_t _size;
		size_t _capacity;
	}SeqList;

	void SeqListInit(SeqList* ps, size_t n) // cpp->���캯�����
	{}
	void SeqListDestory(SeqList* ps)        // cpp->�����������
	{}
	void SeqListPrint(SeqList* ps);
	void SeqListCheckCapacity(SeqList* ps);
	void SeqListPushBack(SeqList* ps, SLDataType x)  // c����������cpp->������ֻ��һ��������ʵ��Ҳ����������һ����������this
	{}
	void SeqListPopBack(SeqList* ps);
}

namespace bit_cpp
{
	// typedef int SLDataType;
	template<class T>
	class SeqList
	{
	public:
		SeqList(size_t n = 10)
			:_a(new T[n])
			, _size(0)
			, _capcity(n)
		{}

		~SeqList()
		{
			if (_a != nullptr)
			{
				delete[] _a;
				_size = _capcity = 0;
			}

		}

		void PushBack(T x)
		{
			// ...
		}

		// a[i]
		// a[i] = 0;
		T& operator[](size_t i)
		{
			// ����i���ʵ�λ���Ƿ�Ϸ�
			assert(i < _size);

			return _a[i];
		}

		// ...

	private:
		T*           _a;
		size_t      _size;
		size_t      _capcity;
	};
	
}

int main()
{
	//// C��ʹ��˳���
	//bit_c::SeqList seqc;
	//bit_c::SeqListInit(&seqc, 10);
	//// ...
	//bit_c::SeqListPushBack(&seqc, 1);
	//bit_c::SeqListPushBack(&seqc, 2);
	//bit_c::SeqListPushBack(&seqc, 3);
	//bit_c::SeqListDestory(&seqc);


	// CPP��ʹ��˳���
	bit_cpp::SeqList<int> seqcpp1;
	seqcpp1.PushBack(1);
	seqcpp1.PushBack(2);
	seqcpp1.PushBack(3);

	// ����i��λ�õ�����
	cout << seqcpp1[0] << endl;
	// д��i��λ������
	// seqcpp1.operator[](0) = 0;
	seqcpp1[0] = 0;
	seqcpp1[1] = 0;

	bit_cpp::SeqList<double> seqcpp2;
	seqcpp2.PushBack(1.1);
	seqcpp2.PushBack(2.2);
	seqcpp2.PushBack(3.3);


	return 0;
}

