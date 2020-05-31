#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	std::string s1;
//	std::string s2("helloworld");
//	std::string s3(s2);
//	s1 = s3;
//
//	//�������ַ�ʽ��������
//	std::string s4(s3, 5, 5);
//	std::string s5(5, 'a');
//
//	/*std::cout << s1 << std::endl;
//	std::cout << s2 << std::endl;
//	std::cout << s3 << std::endl;
//	std::cout << s4 << std::endl;
//	std::cout << s5 << std::endl;*/
//
//	// ���������һ������ȡ�����е�ÿһ��Ԫ��
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		std::cout << s1[i] << "";
//	}
//	std::cout << std::endl;
//	return 0;
//}

//int main()
//{
//	string s1;  //�޲ι���
//	string s2("helloworld");  //���ι���
//	string s3(s2);  //��������
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	s1 = s3;  //operator=
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//
//	return 0;
//}

int main()
{
	string s1;		
	string s2("hello world");
	cout << s1.size() << endl;  // ����������Ϊ����stl�����õ���size()
	cout << s2.size() << endl;
	cout << s1.length() << endl;
	cout << s2.length() << endl;
	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;
	cout << s1.empty() << endl;
	cout << s2.empty() << endl;
	cout << s2.size() << endl;
	s2.clear();
	cout << s2.size() << endl;

	// ����û��
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	return 0;
}

// string/vector��������ݵģ�

#include <iostream>
#include <string>
using namespace std;

int main()
{

	string s;
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	// string������һ��ȱ�㣬�������ݣ��ռ䲻����Ҫ���ݣ����������������ġ�
	//s.reserve(1000);  // reserve->����   ʹ��ǰ�᣺��֪�������Ҫ���ٿռ������£�����ʡȥ���ݿ���
	s.resize(1000, 'c'); // ->s[i] = 'c';
	//for (int i = 0; i < 1000; ++i)
	//{
	//	//s.push_back('c');
	//	//s[i] = 'c';
	//	if (sz != s.capacity())
	//	{

	//		sz = s.capacity();
	//		cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	return 0;
}

int main()
{

	string s("hello world");
	s.resize(5);
	cout << s << endl;
	s.reserve(1000);
	cout << s.capacity() << endl;
	s.reserve(16);
	cout << s.capacity() << endl;

	return 0;
}

//string�Ĵ�ӡ�ͱ���
int main()
{
	string s1("hello world");
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	s1.resize(20);
	s1.push_back('x');
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	return 0;
}

class String
{
public:
	typedef char* iterator;

	iterator begin()
	{
		return nullptr;
	}
};

String s;
String::iterator it = s.begin();

void Func(const string& str)
{
	int value = 0;
	//�ܱ������ʣ����ǲ����޸ķ��ʵ�ֵ
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		//*it = '1';
		value *= 10;
		value += (*it - '0');
		++it;
	}
	cout << value << endl;
}

int main()
{
	// ת�������Σ���ô�㣿
	string s("12345");
	int value = 0;

	// ����s�������ַ�ʽ��1��size+[] 
	for (size_t i = 0; i < s.size(); ++i)
	{
		value *= 10;
		value += (s[i] - '0');
	}
	cout << value << endl;

	// 2�������� �ȼ�ס����÷�
	//[begin(), end())
	value = 0;
	// �ܱ������ʣ�Ҳ���޸ķ��ʵ�ֵ
	string::iterator it = s.begin();
	while (it != s.end())
	{
		// *it = '1';
		value *= 10;
		value += (*it - '0');
		++it;
	}
	cout << value << endl;

	// ���������
	value = 0;
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		value *= 10;
		value += (*rit - '0');
		++rit;
	}
	cout << value << endl;

	Func(s);

	return 0;
}

int main()
{
	string s("hello world");
	s[0] = 'x'; // s.operator[](0)
	cout << s << endl;

	return 0;
}

int main()
{
	string s("hello world");
	s.push_back('!');        // β��һ���ַ�
	s.append("hello world"); // β���ַ���
	cout << s << endl;

	// �Ҹ��Ƽ�������������+=
	string s1("hello");
	string s2("world");
	s1 += ' ';
	s1 += "world";
	s1 += ' ';
	s1 += s2;
	cout << s1 << endl;

	return 0;
}

int main()
{
	// Ҫ��ȡ����׺
	string file1("string.cpp.zip");
	string file2("string.txt.c.doc");

	size_t pos1 = file1.rfind('.');
	cout << file1.substr(pos1, string::npos) << endl;

	size_t pos2 = file2.rfind('.');
	cout << file2.substr(pos2, file2.size()-pos2) << endl;

	string url1("http://www.cplusplus.com/reference/string/string/find/");
	string url2("https://www.tengxun.com/find/");
	string url3("ftp://www.baidu.com/string/string/find/");

	// ȡ��url�е�����
	size_t urlpos1 = url1.find("://");
	urlpos1 += 3;
	size_t urlend1 = url1.find('/', urlpos1);
	cout << url1.substr(urlpos1, urlend1 - urlpos1)<<endl;

	size_t urlpos2 = url2.find("://");
	urlpos2 += 3;
	size_t urlend2 = url2.find('/', urlpos2);
	cout << url2.substr(urlpos2, urlend2 - urlpos2) << endl;

	size_t urlpos3 = url3.find("://");
	urlpos3 += 3;
	size_t urlend3 = url3.find('/', urlpos3);
	cout << url3.substr(urlpos3, urlend3 - urlpos3) << endl;

	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	string str;
	//cin >> str; cin�����ո���߻����������ֵ�ͽ�����
	getline(cin, str);
	size_t pos = str.rfind(' ');
	cout << str.size() - pos - 1 << endl;

	/*int i, j, k;
	cin >> i >> j >> k;
	cout << i << endl;
	cout << j << endl;
	cout << k << endl;*/

	return 0;
}

#include <string>

// string��Ƶù��ڸ��ӣ��ӿ�̫�࣬ѧϰ�ɳ�̫�ߡ�
int main()
{
	string s1;
	s1 += 'h';
	s1 += "ello";
	cout << s1 << endl;

	// ���龡������������Ϊ����ʱ�临�Ӷ�ΪO(N)
	s1.insert(0, "world");
	s1.insert(0, " ");
	s1.insert(6, " ");
	cout << s1 << endl;

	/*s1.erase(s1.begin());
	cout << s1 << endl;
	s1.erase(s1.begin()+5);
	cout << s1 << endl;*/
	//s1.erase();  // ->s1.clear();

	//  ���龡������������Ϊ����ʱ�临�Ӷ�ΪO(N)
	s1.erase(5, 3);
	cout << s1 << endl;

	return 0;
}


#include <string>

// string��Ƶù��ڸ��ӣ��ӿ�̫�࣬ѧϰ�ɳ�̫�ߡ�
int main()
{
/*	string s1("hello wrold");
	size_t pos = s1.find('x');
	if (pos != string::npos)
	{
		cout << pos << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}*/

	string s1("hello world");
	string s2("hello world");

	// ʵ���зǳ����Ƽ����ʹ��+, ����ʹ��+=
	// string operator+ (const string& lhs, const string& rhs);
	string s3 = s1 + s2;
	s1 + "world";
	// "world" + s1; ����������

	// string& operator+= (const string& str);
	//string s3 = s1;
	//s3 += s2;

	// ��strcmp�ȽϹ���һ��, ���ַ���ASCII ��ȥ�Ƚ�
	//cout << (s1 < s3) << endl;
	//cout << (s1 == s3) << endl;

	// ��Χfor�ı����������STL�е��������������������ַ�ʽ����
	// д�������
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

namespace bit
{
	class string
	{
	public:
		/*string()
		:_str(new char[1])
		{
		_str[0] = '\0';
		}

		string(const char* str)
		:_str(new char[strlen(str) + 1])
		{
		strcpy(_str, str);
		}*/

		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		// s3(s1)
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//string& operator=(const string& s)

		~string()
		{
			delete[] _str;
		}

		const char* c_str()
		{
			return _str;
		}

	private:
		char* _str;
	};
}

int main()
{
	bit::string s1("hello");
	cout << s1.c_str() << endl;

	bit::string s2;
	cout << s2.c_str() << endl;

	bit::string s3(s1);
	cout << s3.c_str() << endl;

	return 0;
}