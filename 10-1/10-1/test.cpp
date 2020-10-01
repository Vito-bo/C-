#include <iostream>
using namespace std;
#include <vector>
#include <stack>


//��ָofferˢ��

#if 0
//13-�������˶��ķ�Χ
//��������㷨+�����㷨���
class Solution {
public:
	int movingCount(int m, int n, int k) {
		if (k == 0)
			return 1;
		//��¼��λ���Ƿ񱻷��ʹ�
		vector<vector<bool>> valid(m, vector<bool>(n, true));
		return dfs(valid, m, n, 0, 0, k);
	}

	int dfs(vector<vector<bool>>& valid, int m, int n, int row, int col, int k)
	{
		int sum = GetSum(row) + GetSum(col);
		//�����Խ�磬���ߺʹ���K,�����Ѿ����ʹ��ˣ�����0
		if (row >= m || col >= n || sum > k || !valid[row][col])
			return 0;
		valid[row][col] = false;//��λ��״̬Ϊ���Է��ʹ�
		return 1 + dfs(valid, m, n, row + 1, col, k) + dfs(valid, m, n, row, col + 1, k);
	}

	//��ĳ������������λ֮��
	int GetSum(int num)
	{
		if (num<10)
			return num;
		int sum = 0;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};
#endif

//06-��β��ͷ��ӡ����

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//����1����������
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> res; //��������洢������������
		while (head)
		{
			res.push_back(head->val);
			head = head->next;
		}
		//��ת����
		reverse(res.begin(), res.end());
		return res;
	}
};

//����2������ջ�ĺ���ȳ�ԭ��
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> res;
		stack<int> s;
		//��ջ
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		//��ջ
		while (!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}
};