
#include <iostream>
#include <vector>
using namespace std;

#if 0
class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
// ����ͱ���
void Test1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(10);
	vector<Date> v4(10);

	// �������͵Ĺ���
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(arr[0]));
	// ��������
	vector<int> v6(v5);

	// C++11������
	vector<int> v7{ 1, 2, 3, 4, 5 };

	// ������ʽ
	for (size_t i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	// C++11 ��Χfor����
	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	// ��������ʽ����
	vector<int>::iterator it = v7.begin();
	while (it != v7.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

// ��������
void Test2()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8};
	cout << v.size() << endl;  
	cout << v.capacity() << endl;
	

	v.resize(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(11);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(17);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(30);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}

// Ԫ�ط���
void Test3()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	v[0] = 100;
	v.back() = 10;
	v.front() = 20;
	v.at(3) = 200;
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v.at(3) << endl;

	// ����Խ��
	//v[5] = 90;
	//v.at(5) = 99;
}

// push_back
// vecotr�����ݻ���
// 1.vector�����ݻ��� vs:1.5�� linux;2��
// 2.��������һ�����һ������
//	ע�⣺һ����֪���洢���ٸ�Ԫ�أ���ǰ���ռ�Ԥ����
void Test4()
{
	vector<int> v;
	v.reserve(100);
	size_t capacity = v.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (capacity != v.capacity())
		{
			cout << capacity << endl;
			capacity = v.capacity();
		}
	}
}

void TestPushBack()
{
	Date d(2020, 11, 20);
	vector<Date> v;

	// ע�⣺push_back()����ֱ�ӽ�dβ�嵽vector��
	// ʵ���ϲ������d��һ�ݿ���
	v.push_back(d);
	cout << &v << endl;
}
#endif 


// �����ɾ��
void Test5()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	v.insert(v.begin(), 0);

	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
		v.insert(pos, 4, 6);

	//v.insert(v.begin() + 1, v.begin(), v.end());

	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 5);
	v.erase(v.begin(), v.end()); // clear()

}

// ������ʧЧ�����ݵ���
void Test6()
{
	vector<int> v{ 1, 2, 3 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	auto it = v.begin();
	v.assign(10, 5);
	//assign() ����Ҫô������[start, end)��Ԫ�ظ�����ǰvector,
	//���߸�num��ֵΪval��Ԫ�ص�vector��.����������������Ϊvector��ֵ��ǰ������.

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

// ������ʧЧ��ɾ������
void Test7()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	v.erase(it);
	
	// it = v.begin();
	cout << *it << endl;
}
//������ʧЧ����������
void Test8()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2, 3, 4, 5 };

	auto it1 = v1.begin();
	auto it2 = v2.begin();

	v1.swap(v2);
	// it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}
// �ܽ᣺������ʧЧ����������ʽ������ɾ����ǰ��iterator��ʹ��������Ԫ�ص�iterator��ʧЧ��
// ��Ϊ˳�������ڴ������������ɾ��һ��Ԫ�ص��º�������Ԫ�ػ���ǰ�ƶ�һ��λ�ã�ɾ����һ��Ԫ�أ���Ԫ�غ��������Ԫ�ض�Ҫ�ƶ�λ�ã�����it++��ָ�����δ֪�ڴ棩
// ������������п������������ʧЧ��λ��֮����ʹ�õ�����ʱ���¸��õ�������ֵ

// ����ʹ�õ�������vector�е�����Ԫ��ɾ����
void Test9()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it); //erase()�����ر�ɾ��Ԫ�ص���һ��λ��
		// ++it;
	}
}


// vector����ʹ�ó������������
void Test10()
{
	// 5*6
	vector<vector<int>> vv;
	vv.resize(5);
	for (int i = 0; i < vv.size(); ++i)
		vv.resize(6);
	for (int i = 0; i < vv.size(); ++i)
	{
		for (int j = 0; j < vv[i].size(); ++j)
			vv[i][j] = j + 1;
	}
	
	// 5*6
	vector<vector<int>> vv(5, vector<int>(6));

	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			vv[i][j] = j + 1;
		}
	}

	// 5*6
	vector<vector<int>> vv(5, vector<int>{1, 2, 3, 4, 5, 6});
}

int main()
{
	Test10();
	return 0;
}