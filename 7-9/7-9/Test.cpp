//ÿ��һ��7-9
//1.�ռ����б�
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cin.get(); //����س�
		string name;
		for (int i = 0; i<n; i++) //���ֱַ���
		{
			bool quote = false;
			getline(cin, name);
			if (name.find(',') != string::npos ||
				name.find(' ') != string::npos) //�ҵ����Ż��߿ո񣬾�Ҫ��˫����
			{
				quote = true;
			}
			if (quote)
			{
				putchar('\"');
			}
			cout << name;
			if (quote)
			{
				putchar('\"');
			}
			if (i == n - 1) //����Ѿ������һ���ַ������ǾͲ��س�������Ӷ��źͿո�
			{
				putchar('\n');
			}
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return 0;
}

//2.������
#include <iostream>
#include <cstdio>
int main()
{
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	}
	int d;
	while (std::cin >> d)
	{
		printf("%lld\n", n[d - 1]);
	}
}