////ÿ��һ��6-16
////1.��������ת������
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int year, month, day;
//	int arr[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	while (cin >> year >> month >> day)
//	{
//		int sum = 0;
//		sum += arr[month - 1];
//		sum += day;
//		if (month>2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//				sum += 1;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}
//2.���˵Ĵ���
#include <iostream>
#include <algorithm>
using namespace std;

/*
getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������һ��λ�ý���
x[]: �����е�������
n: �������
pos: ��ǰ������λ��
sum: ��Ŀǰλ�õ��ۼӺ�
multi: ��Ŀǰλ�õ��ۻ�ֵ
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//ѭ����������λ��i��ʼ���п��ܵ����
	for (int i = pos; i<n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ���
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//��β�����Ҫ���ҵ�ǰԪ��ֵΪ1��������������
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//���sum����multi,������û�з���Ҫ��������
			break;
		}
		//Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi
		sum -= x[i];
		multi /= x[i];
		//������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		//�ӵ�һ��λ�ÿ�ʼ����
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}
