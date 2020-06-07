#include <iostream>
//#include <string>
#include <assert.h>
#include <stdlib.h>
using namespace std;

class string
{
public:
	string(const char* str = "")
	{
		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	string(const string& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	string& operator=(const string& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('b');
	s1.append(1, 'i');
	s1 += 't';
	cout << s1 << end
	return 0;
}



////string�����ķ��ʷ�ʽ����������
//void Teststring1()
//{
//	string s1("hello world");
//	//const���Ͷ������޸�
//	const string s2("hello girl");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl; 
//}
//void Teststring2()
//{
//	string s("hello world");
//	//���ֱ�����ʽ
//	//1.for+operator[]ʹ�����
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i];
//	}
//	cout << endl;
//
//	//������
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//
//	//3.��Χfor
//	for (auto ch : s)
//	{
//		cout << ch;
//	}
//	cout << endl;
//}
//void Teststring3()
//{
//	string str;
//	str.push_back(' ');  //��str�����ո�
//	str.append("hello"); //��str��׷��һ���ַ���"hello"
//	str += 'b';          //��str��׷��һ���ַ�'b'
//	str += "it";         //��str��׷��һ���ַ���"it"
//	cout << str << endl;
//	cout << str.c_str() << endl;//��C���Եķ�ʽ��ӡ�ַ���
//
//	//��ȡfile�ĺ�׺
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	//npos��string�����һ����̬��Ա����
//	//static const size_t npos=-1;
//
//	//ȡ��url�е�����
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string adderss = url.substr(start,finish - start);
//	cout << adderss << endl;
//
//	//ɾ��url��Э��ǰ׺
//	pos = url.find("://");
//	url.erase(0,pos + 3);
//	cout << url <<endl;
//}
//
//int main()
//{
//	//Teststring1();
//	//Teststring2();
//	//Teststring3();
//
//	return 0;
//
//}


