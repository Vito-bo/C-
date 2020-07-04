//ÿ��һ��7-2
//1.����λ������������ż��λ����ż��
class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i<len && j<len)
		{
			if ((arr[i] % 2) == 0)
			{
				//ż��λ��Ѱ�ҷ�ż��
				i += 2;
				continue;
			}
			if ((arr[j] % 2) != 0)
			{
				//����λ��Ѱ�ҷ�����
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);
		}
	}
};
//2.���ӷ���
#include <iostream>
#include <string>
#include <math.h>
int main()
{
	int n;
	while (std::cin >> n) {
		if (n == 0)
			break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}
	return 0;
}