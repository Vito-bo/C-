//ÿ��һ��7.1
//1.���ټӼ��˳��ļӷ�����
class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0)
		{
			int sum = num1^num2; //�õ���Ӻ󲻰�����λ������
			int carray = (num1&num2) << 1;//�õ�������ӵĽ�λ
			num1 = sum;           //��������ӣ�ֱ����λΪ0
			num2 = carray;
		}
		return num1;
	}
};
//2.������
#include <iostream>
using namespace std;
#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))
int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		//�����߽���������������бȽ�
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) {
			cout << "Yes" << std::endl;
		}
		else {
			cout << "No" << std::endl;
		}
	}
	return 0;
}