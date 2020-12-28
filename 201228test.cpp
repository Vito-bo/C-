

#include <iostream>
#include <vector>
using namespace std;

//��ָoffer29-˳ʱ���ӡ����
//����һ��
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return{};

		vector<int> ret;
		int left = 0; //��߽�
		int top = 0;  //�ϱ߽�
		int right = matrix[0].size() - 1;
		int bottom = matrix.size() - 1;

		// ѭ����ӡ
		while (left <= right && top <= bottom)
		{
			// �������Ҵ�ӡ
			for (int i = left; i <= right; i++)
			{
				ret.push_back(matrix[top][i]);
			}
			top++;

			// �������´�ӡ
			for (int i = top; i <= bottom; i++)
			{
				ret.push_back(matrix[i][right]);
			}
			right--;

			// ���������ӡ
			for (int i = right; i >= left && top <= bottom; i--)
			{
				ret.push_back(matrix[bottom][i]);
			}
			bottom--;

			// �������ϴ�ӡ
			for (int i = bottom; i >= top && left <= right; i--)
			{
				ret.push_back(matrix[i][left]);
			}
			left++;
		}
		return ret;
	}
};

//������
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return{};

		vector<int> ret;
		int left = 0; //��߽�
		int top = 0;  //�ϱ߽�
		int right = matrix[0].size() - 1; //�ұ߽�
		int bottom = matrix.size() - 1;   //�±߽�

		// ѭ����ӡ
		while (true)
		{
			// �������Ҵ�ӡ
			for (int i = left; i <= right; i++)
			{
				ret.push_back(matrix[top][i]);
			}
			if (++top>bottom)
				break;

			// �������´�ӡ
			for (int i = top; i <= bottom; i++)
			{
				ret.push_back(matrix[i][right]);
			}
			if (--right<left)
				break;

			// ���������ӡ
			for (int i = right; i >= left && top <= bottom; i--)
			{
				ret.push_back(matrix[bottom][i]);
			}
			if (--bottom<top)
				break;

			// �������ϴ�ӡ
			for (int i = bottom; i >= top && left <= right; i--)
			{
				ret.push_back(matrix[i][left]);
			}
			if (++left>right)
				break;
		}
		return ret;
	}
};

//��ָoffer17-��ӡ��1������nλ��
class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> ret;
		int max = pow(10, n);
		for (int i = 1; i <= (max - 1); i++)
			ret.push_back(i);
		return ret;
	}

};

// ��ָoffer24-��ת����
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x)
		, next(NULL) 
	{}
	
};

// ��ָ�뷨
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = nullptr;
		ListNode* prev = head;
		while (prev != nullptr)
		{
			ListNode* tmp = prev->next;
			prev->next = cur;
			cur = prev;
			prev = tmp;
		}
		return cur;
	}
};
int main()
{
	return 0;
}