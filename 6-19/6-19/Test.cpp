////ÿ��һ��6-19
////1.������ǵı���
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	while (cin >> n)
//	{
//		m = 2 * n - 1;
//		vector<vector<int>> dp(n, vector<int>(m, 0));
//		dp[0][0] = 1;
//		for (int i = 1; i<n; i++)
//		{
//			//��һ�к����һ�ж�Ϊ1
//			dp[i][0] = dp[i][2 * i] = 1;
//			for (int j = 1; j<2 * i; ++j)
//			{
//				if (j == 1)
//					//����ǵڶ��У���ֻ������Ԫ��֮��
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//				else
//					//��i,jԪ�ص�����һ�е�j-2,j-1,j����Ԫ��֮��
//					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
//			}
//		}
//		int k;
//		for (k = 0; k<m; k++)
//		{
//			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
//			{
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//		if (k == m)
//			cout << -1 << endl;
//	}
//	return 0;
//}

//2.�������������
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string AddString(string num1, string num2)
{
	//�ɵ�λ���λ���
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	//��ǰλ����ӽ��
	int carry = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			carry += num1[i] - '0';
		if (j >= 0)
			carry += num2[j] - '0';
		//��ǰλ�����ֵ������10
		result += (char)(carry % 10 + '0');
		//�������10�����Ͻ�һλ
		carry /= 10;
		i--;
		j--;
	}
	//�����֮��������н�λ�����ټ�1
	if (carry == 1)
		result += '1';
	//��������
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << AddString(s1, s2) << endl;
	}
	return 0;
}
