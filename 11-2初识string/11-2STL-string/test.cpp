#include<iostream>
#include<assert.h>
#include <string>
using namespace std;

// string��ʶ

#if 0
// �ַ�����������'\0'��Ϊ��β�������ַ�����
// C������û���ַ�������
// �����ַ���ʱ�����뱣֤�ַ������һ��Ԫ��Ϊ'\0'
// C�����б�ʾ�ַ����ķ������ǽ��ַ�����Ϊ�ַ�����������ģ��ַ���������ŵ�����Ԫ���еġ�

int main()
{
	//1.����ַ�������Ԫ����û��'\0',���ַ�������Ϊ�ַ���ʵ�ʳ���+1
	char ch1[6] = { 'h', 'e', 'l', 'l', 'o' };
	char ch2[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	char ch3[] = "hello";
	return 0;
}
C++��ר���ṩ��һЩ���������ַ��������Ŀ⺯��--<string.h>
strcpy / strlen / strcmp / strcat / strchr..һ��Ҫ��ģ��ʵ��
�û��ڽ����ַ�������ʱ����Ҫ�Լ�����ռ�
C++���ַ�������--string��
string���еĽӿڷ�Ϊ���¼���ģ�飺
����������/������/�������/Ԫ�ط��ʵ�/�޸�/

#endif



void Test1()
{
	string s("welcome to xian lintong");
	
	//size��length�������ַ�������Ч����
	cout << s.size() << endl;
	cout << s.length() << endl;

	//capacity��ײ�ռ��ܵĴ�С
	cout << s.capacity() << endl;

	//�����ַ����Ƿ�Ϊ�գ����ַ�����
	if (!s.empty())
		cout << "not empty" << endl;
	else
		cout << "empty" << endl;

	// ��s����Ч�ַ����
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl; //�ռ���������

	if (!s.empty())
		cout << "not empty" << endl;
	else
		cout << "empty" << endl;
}
void Test2()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// resize�����ַ�����С
	// ���nС�ڵ�ǰ�ַ������ȣ��򽫵�ǰֵ���̵�n���ַ�����ɾ����n���ַ�֮����ַ���
	// ���n���ڵ�ǰ�ַ�������ͨ����β�����������������ַ������䵱ǰ�ַ�������n�Ĵ�С
	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '*');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(34);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// resizeֻ�ǽ���ЧԪ�ظ���������n��
	// �ײ�����û�з����仯
	s.resize(29);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void Test3()
{
	//sizeof(string)���ַ����ĳ������޹صģ���һ��ϵͳ�����е�sizeof(string)��һ���̶�ֵ������ͱ��������
	//cout << sizeof(string) << endl;//28

	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// reserve�����ַ�����������Ӧ�仯�Ĵ�С��ʹ�䳤�����Ϊn���ַ�
	// ���n���ڵ�ǰ�ַ����������ú�����ʹ�����������ӵ�n���ַ�(�����)
	// ��Ӱ���ַ������ȣ�Ҳ���ܸ��������ݡ�
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(18);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(28);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string s1("hello world!!!!"); //strtok
	char* p = (char*)s1.c_str();
}

// �ַ���׷��
void Test4()
{
	string s1;
	string s2("hello");
	s1 += s2;
	s1 += ' ';
	s1 += "world";
	s1.push_back('!');
	cout << s1 << endl;
	
	s1.append("nihao xian");
	cout << s1 << endl;
}

void Test5()
{
	string s("hello");

	size_t pos = s.find('o');
	if (pos != string::npos)// npos�ַ�����β
	{
		s.insert(pos, "world");
	}
	cout << s << endl;

	// insert��ָ��λ�ò����ַ�
	s.insert(s.begin(), 3, '*');
	cout << s << endl;

	// eraseɾ�����ַ�λ��pos��ʼ��len���ַ����������̫�̻���len=npos,ɾ��Ԫ��ֱ���ַ���������
	// Ĭ�ϲ�����ɾ���ַ����е������ַ�����clear()��ͬ��
	s.erase(s.begin());
	cout << s << endl;
	s.erase(s.begin(), s.begin() + 3);
	cout << s << endl;
	s.erase();
}

void Test6()
{
	string s1("hello");
	string s2("world");
	swap(s1, s2);
	cout << s1 << " " << s2 << endl;

	s1.swap(s2);
	cout << s1 << " " << s2 << endl;
}

// atoi(��ʾ ascii to integer)�ǰ��ַ���ת����������
void Test7()
{
	string s("12345");
	int value = atoi(s.c_str());
	cout << value << endl;
}

// find()
void Test8()
{
	string s("http://www.baidu.com");
	size_t pos = s.find("www");
	if (pos != string::npos)
	{
		string ret = s.substr(pos);
		cout << ret << endl;
	}
}

// �ж��е���
// ���ʺ͵���֮��ʹ�ÿո����������֪�����һ�����ʵĳ���
void Test9()
{
	string s;
	// ѭ������һ���ַ���
	while (getline(cin, s))
	{
		// rfind()������ң�����λ��
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
}

void Test10()
{
	string s;
	// һ�ν���һ��
	while (cin >> s)
	{
		cout << s << endl;
	}
}

// �ַ����Ƚϣ�����ASCII���������ַ��Ƚ�
void Test11()
{
	string s1("ningbo");
	string s2("mengmeng");
	if (s1 > s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;
}

//�ַ��������ֱ���
void Test12()
{
	string s("welcome to xian");
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
	}
	cout << endl;

	for (auto e : s)
		cout << e;
	cout << endl;

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

// vs��string������ݹ��ɣ�1.5������
void Test13()
{
	string s;
	size_t sz = s.capacity();
	cout << "make s gorw:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	//Test11();
	//Test12();
	Test13();

	return 0;
}

