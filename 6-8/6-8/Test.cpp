//ÿ��һ��6-8
////1.Fibonacci����
//#include <iostream>
//using namespace std;
//int main()
//{
//	int f0 = 0, f1 = 1, f;
//	int N;
//	int L = 0, R = 0;
//	cin >> N;
//	while (1)
//	{
//		f = f0 + f1;
//		f0 = f1;
//		f1 = f;
//		//�ҵ���NС�Ҿ���N����������������
//		if (f<N)
//			L = N - f;
//		else
//		{
//			//�ҵ���N���Ҿ���N����������������
//			R = f - N;
//			break;
//		}
//	}
//	//��ȡ��С����
//	cout << min(L, R) << endl;
//	return 0;
//}

//2.�Ϸ����������ж�
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> sc;
		for (auto ele : A) {
			switch (ele) {
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
						if (sc.empty() || sc.top() != '(')
							return false;
						else
							sc.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};