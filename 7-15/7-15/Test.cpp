//ÿ��һ��7-15
//1.�ַ�������
/*
�����ַ���������26���ƽ��м���
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define N 1000007
#include<math.h>
using namespace std;
int main()
{
	//�������и��������ӣ�����ַ���ֻ����Сд��ĸ����Ȼ�𰸾Ͳ�Ӧ����56��
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		//ֻ����Сд��ĸ���ַ������Կ���26���Ƶ�����
		//��s1��s2������len2����
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		// ȷ��s1��s2�������ַ���ÿ��λ���ϵĲ�ֵ
		vector<int> array;
		for (int i = 0; i<len2; i++)
		{
			array.push_back(s2[i] - s1[i]);
		} 
		// ȷ��len1��len2֮�����ɵĲ�ͬ�ַ����ĸ���
		int result = 0;
		for (int i = len1; i <= len2; i++)
		{
			for (int k = 0; k<i; k++)
			{
				result += array[k] * pow(26, i - 1 - k);
			}
		} 
		// �����ַ�����󶼲�������s2�����������Ҫ��1��
		cout << result - 1 << endl;
	} 
	return 0;
}
//������Ӵ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B) 
	{
		int aLength = A.length();
		int bLength = B.length();
		// ��������״̬ת�Ʒ����м����ľ���
		vector<vector<int> > dp(aLength, vector<int>(bLength, 0));
		// ��ʼ��dp����߽磺�߽��ַ�Ҫô�ڣ�Ҫô����
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i<aLength; i++) 
		{
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		} 
		for (int j = 1; j<bLength; j++) 
		{
				dp[0][j] = (A[0] == B[j]) ? 1 : 0;
				dp[0][j] = max(dp[0][j - 1], dp[0][j]);
			} 
		// ����״̬ת�Ʒ��̽��м���
		for (int i = 1; i<aLength; i++) 
		{
			for (int j = 1; j<bLength; j++) 
			{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					if (A[i] == B[j]) 
					{
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
					}
			}
		} 
		cout << dp[aLength - 1][bLength - 1] << endl;
	} 
	return 0;
}