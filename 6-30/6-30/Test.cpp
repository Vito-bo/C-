//ÿ��һ��6-30
//1.��̬��̨��
class Solution {
public:
	int jumpFloorII(int number) {
		//2^(n-1) == 1 << (n-1)
		return 1 << (number - 1);
	}
};

//2.�쵽������
#include <iostream>
using namespace std;
int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		//�ܳ���2*r*3.1415
		//����n
		if (n > (2 * r*3.1415))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}