//ÿ��һ��7-21
//1.����������
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i<s.size(); i++)
		{
			//1.����_��ֱ������
			if (s[i] == '_')
				continue;
			//2.�����һ���ַ���_ ����һ���ַ�ת��Ϊ��д��ĸ
			if (i>0 && s[i - 1] == '_')
				cout << (char)toupper(s[i]);
			else
				cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
//2.���ʵ���
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
void deal(vector<string>&res, string& str, char delim = ' ')
{
	// ���ַ��������з�, ���� stringstream ���. Ĭ�Ϸָ���ǿո�.
	// stringstream ����������з�, ��������ַ���������֮���ת��.
	stringstream ss;
	ss << str;
	string tmp;
	while (ss >> tmp) {
		res.push_back(tmp);
	}
}
int main()
{
	string str;
	while (getline(cin, str)) {
		vector<string> res;
		for (int i = 0; i < str.size(); i++)
			// �ȶԷָ�����д���. ������ַָ��, ��ͳһ����ɿո�.
		if (!isalnum(str[i]))
			str[i] = ' ';
		// ���ַ��������з�
		deal(res, str);
		cout << res[res.size() - 1];
		for (int i = res.size() - 2; i >= 0; i--)
			cout << " " << res[i];
		cout << endl;
	}
	return 0;
}