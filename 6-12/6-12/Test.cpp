//ÿ��һ��6-12
//1.�����������
class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

//2.�������bit��
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n����32�ξͱ�Ϊ0
		while (n)
		{
			//��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1)
			{
				//���1��ֵ�����������ۼӣ����Ҹ���������
				++count;
				maxCount = max(count, maxCount);
			} 
			else
			{
				//���1��ֵ�������������ۼ�
				count = 0;
			} 
			// ����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
				n = n >> 1;
		} 
		cout << maxCount << endl;
	} 
	return 0;
}