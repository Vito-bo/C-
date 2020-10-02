
#include <iostream>
using namespace std;
#include <vector>

#if 0
//07-�ؽ�������
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0)//û�н�㣬���ؿ�
			return nullptr;
		if (preorder.size() == 1) //����һ�����
		{
			TreeNode *root = new TreeNode(preorder[0]);
			return root;
		}

		//ǰ�������һ��Ϊ���ڵ�
		TreeNode *root = new TreeNode(preorder[0]);
		auto itr = inorder.begin();
		while (*itr != preorder[0])//�ҵ�����������ڵ㣬�ָ���������
			++itr;
		//����������ǰ����������
		int left = itr - inorder.begin(); //����������
		vector<int> leftpre(preorder.begin() + 1, preorder.begin() + 1 + left);//������ǰ��
		vector<int> leftin(inorder.begin(), itr);//����������

		//����������ǰ����������
		vector<int> rightpre(preorder.begin() + 1 + left, preorder.end());//������ǰ��
		vector<int> rightin(++itr, inorder.end());

		//�ݹ����
		root->left = buildTree(leftpre, leftin);
		root->right = buildTree(rightpre, rightin);

		//���ظ��ڵ�
		return root;
	}
};
#endif

#if 0
//14-1������
//��̬�滮���
//����dp(n)������Ϊn�����ӷָ��������ܳ˻�
//�ȴ�n�м���һ�γ���Ϊi,��dp(n)=dp(n-i)*dp(i)�����ֵ

class Solution {
public:
	int dp(int n, vector<int>& res)
	{
		int ans = n;
		for (int i = 1; i <= n / 2; i++)
		{
			if (res[n - i] == 0)
				res[n - i] = dp[n - i, res];
			if (res[i] == 0)
				res[n - i] == dp(i, res);
			ans = max(ans, res[n - i] * res[i]);
		}
		return ans;
	}

	int cuttingRope(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		vector<int> res(n, 0);
		return dp(n, res);
	}
};
#endif

//25-�ϲ��������������

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(1);
		ListNode* ret = head;
		while (l1 != NULL && l2 != NULL) 
		{
			if (l1->val < l2->val) 
			{
				head->next = l1;
				l1 = l1->next;
			}
			else 
			{
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		head->next = l1 == NULL ? l2 : l1;
		return ret->next;
	}
};
