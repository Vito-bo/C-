
#include<iostream>
using namespace std;
#include<assert.h>

#if 0
//ģ��
�����⣺дһ��ͨ�����͵ļӷ�������
д�������޹صĴ��룬��õķ�������ʹ��ģ��
ģ�壺����������ʹ�õ�ģ�ߡ�
	 ģ�岻�������ĺ�����
ģ�壺����ʵ��һЩ�������޹صĴ���
���ͱ�̣��������޹أ������ݽṹ�޹�
ģ���Ƿ��ͱ�̵Ļ�����

ע�⣺����ģ�Ͳ����������ĺ���
�����û����߱��������ɴ���Ĺ���

����ģ��ԭ��
1.��ʽʵ������û����ȷָ��ģ������б�T��ʵ������
	�ڱ���׶Σ���������Ҫ�Դ��ݵ�ʵ�����ͽ�������
	���ݵĽ����ȷ��ģ������б���T��ʵ�����͡�
	���T�����Ϳ���ȷ�����������ɾ������͵ĺ�����
	���T�������޷�ȷ�����򱨴�
2.��ʽʵ��������ȷָ����ģ������б���T��ʵ������
	������ֱ�Ӹ����û����ṩ��T�����������ɴ���������͵ĺ���
	����������֮������������Ͳ�ƥ�䣬��������ʽ����ת��
	���ת���ɹ��������ͨ��
	���ת��ʧ�ܣ��򱨴�
#endif 

#if 0
//ģ�庯��
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//��ʽʵ����:�ñ���������ʵ�����ݲ�����ʵ������
	Add(1, 2);        //Add<int>
	Add(1.0, 2.0);    //Add<double>
	Add('1', '2');     //Add<char>
	Add(1, (int)2.0); //Add<int>

	//��ʽʵ�������ں��������<>��ָ��ģ�������ʵ������
	Add<int>(1, 2.0);
	//Add(1, 2.0);//����ʧ��

	return 0;
}

//���ڷ�ģ�庯����ͬ������ģ�壬���������������ͬ���ڵ���ʱ����ƥ���ģ�庯��
//ģ�庯���������Զ�����ת��������ͨ�������Խ����Զ�����ת��
//��ģ���ຯ��
int Add(int left, int right)
{
	return left + right;
}
//ģ���ຯ��
template<class T1,class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
int main()
{
	Add(1, 2); //���ģ���ຯ��ƥ�䣬����������Ҫ�ػ�
	Add(1, 2.5);//���ñ������ػ���Add�汾
	return 0;
}
#endif 

//��ģ��--�������������࣬��ʵ�����Ľ�������������ࡣ
//˳���
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	SeqList(const SeqList<T>&);
	SeqList<T>& operator=(const SeqList<T>&);

	//ʹ������������ʾ�������������������ⶨ��
	~SeqList();

	size_t size() const
	{
		return _size;
	}

	size_t capacity() const
	{
		return _capacity;
	}
	bool empty() const
	{
		return 0 == _size;
	}
	void push_back(const T& data)
	{
		//�ռ��㹻
		_array[_size++] = data;
	}

	void pop_back()
	{
		--_size;
	}

	// ��ʱ�������г��ԣ����ܸı�
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}
	const T& operator[](size_t index) const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

//ע�⣺��ģ����������ж���ʱ����Ҫ��ģ������б�
template<class T>
SeqList<T>::~SeqList()
{
	if (_array)
	{
		delete[] _array;
		_capacity = 0;
		_size = 0;

	}
}

int main()
{
	SeqList<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);

	cout << s.size() << endl;
	cout << s.capacity() << endl;

	cout << s[0] << endl;
	s[0] = 20;

	cout << s[0] << endl;

	const SeqList<int> s2;
	//s2[0];    //const���͵Ķ����ǲ��ܵ�����ͨ��Ա������
	return 0;
}
 