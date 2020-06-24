////ÿ��һ��6-22
////1.��ˮ��
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		//�һ�����ˮ��
//		int sum = 0;
//		while (n>1)
//		{
//			//ÿ��ƿ��ȡһƿ
//			int result = n / 3;
//			//ÿ�β�����ƿ�Ŀ�ƿ��
//			int num = n % 3;
//			sum = sum + result;
//			//��һ�ο��Զһ��Ŀ�ƿ
//			n = result + num;
//			if (n == 2)
//			{
//				++sum;
//				break;
//			}
//		}
//		cout << sum << endl;
//	}
//	//while(cin>>n)
//	//{
//	//    cout<<n/2<<endl;
//	//}
//	return 0;
//}

//2.���������ַ����е�������Ӵ�
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//����̵��ַ�����Ϊs1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//����и����Ĺ����Ӵ������³���
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}