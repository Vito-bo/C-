//ÿ��һ��7-8
//1.��������
#include <iostream>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		//������s�в���t���ɣ�ֱ����Ҳ�Ҳ���t
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();//�ӹ�t������ĳ���
			++res; //����
		}
		cout << res << endl;
	}
	return 0;
}

//2.��������
#include <iostream>
#define MAX 83 //����ù�ʽ���㣬��Ҫ�����������ֵ
using namespace std;

void solve(long long num[])
{
	for (int i = 2; i<MAX; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
	}
}
//1.�ñ���������
long long sum_traversal(long long num[], int from, int to)
{
	long long ans = 0;
	for (int i = from - 1; i<to; i++)//�������±��from-1������to-1
	{
		ans += num[i];
	}
	return ans;
}
int main()
{
	int from, to;
	long long num[MAX] = { 1, 1 };
	//��ǰ����Fibonacci����
	solve(num);
	while (cin >> from >> to)
	{
		cout << sum_traversal(num, from, to) << endl;
	}
	return 0;
}
