//ÿ��һ��6-29
//1.�Ǽʴ�ս
#include <iostream>
#include <vector>
std::vector<int> a = { 1, 1 };
void data_init()
{
	int i;
	for (i = 2; i<10005; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}
int main()
{
	int n, t;
	data_init();
	while (std::cin >> n)
	{
		while (n--)
		{
			std::cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}

//2.����
#include <iostream>
#include <string>
int numRoot(int num)
{
	int nroot = 0;
	while (num > 0)
	{
		/*ÿ��ֻ��ȡ��λ����---��λ��+ʮλ��*/
		nroot += num % 10;
		num /= 10;
	}
	while (nroot > 9)
	{
		nroot = numRoot(nroot);
	}
	return nroot;
}
int main()
{
	std::string origin;
	while (std::cin >> origin)
	{
		int sum = 0;
		//�Ƚ�ÿһλ������ӵõ��ܺͣ���ֹ���ֹ���
		for (int i = 0; i < origin.length(); i++)
		{
			sum += origin[i] - '0';
		}
		//���ܺ�������
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}