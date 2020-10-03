#include <iostream>
using namespace std;


//��ָofferˢ��
#if 0

//27-�������ľ���
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	//���ݶ�����������������ݹ�ʵ�ֶ������ľ���
	TreeNode* mirrorTree(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		swap(root->left, root->right);
		mirrorTree(root->left);
		mirrorTree(root->right);
		return root;
	}
};

#endif


#if 0
//28-�ԳƵĶ�����

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool check(TreeNode* p, TreeNode* q) 
	{
		if (p == nullptr && q == nullptr) 
			return true;
		if (p == nullptr || q == nullptr || p->val != q->val) 
			return false;
		//����໥�Ƚϣ�����໥�Ƚ�
		return check(p->left, q->right) && check(p->right, q->left);
	}

	bool isSymmetric(TreeNode* root) 
	{
		if (root == nullptr) 
			return true;
		return check(root->left, root->right);
	}
};

#endif


