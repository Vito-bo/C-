//ÿ��һ�� 6-13
//1.�����Ʋ���
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		//��m�Ķ�����ֵ���뵽n�ĵ�jλ����iλ
		//ֻ��Ҫ��m������jλ��Ȼ������n���л�����
		m = m << j;
		return n | m;
	}
};

//2.�������һ��ż����ӽ�����������
#include <iostream>
#include <algorithm>
using namespace std;

//�ж�����
bool IsPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num %i == 0)
			return false;
	}
	return true;
}
int main()
{
	int half;
	int num;
	while (cin >> num)
	{
		half = num / 2;
		int i;
		//���м���������
		for (i = half; i>0; i--)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}