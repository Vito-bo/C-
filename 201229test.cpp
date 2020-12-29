
/*
// ���ű�ѵ��
#include <iostream>
using namespace std;
#define N 1000001
#define M 10007

int n, i, arr[N];
int main()
{
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	for (i = 3; i<=n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2])%M;
	cout << arr[n] << endl;
	return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int r;
	cin >> r;
	double s;
	double PI = atan(1.0) * 4;
	s = PI*r*r;
	printf("%.7lf\n", s); //���˫���ȸ���������
	return 0;
}

#include <iostream>
using namespace std;
#define N 1000000001

int main()
{
	int n;
	cin >> n;
	long long ret;
	ret = n*(n + 1) / 2;
	printf("%I64d\n", ret);
	return 0;
}
*/

//��ָoffer35-����������
class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val)
	{
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return head;
		copyNodes(head); // ���� value �� next
		copyRandom(head); // ���� random
		return getCopy(head); // ��ȡ���µ�����
	}
	void copyNodes(Node* head)
	{
		// �� a -> b -> c �������� a -> a' -> b -> b' -> c -> c'
		if (!head) return;
		Node* pos = head;
		while (pos)
		{
			Node* copy = new Node(pos->val);
			Node* nextPtr = pos->next;
			pos->next = copy;
			copy->next = nextPtr;
			pos = copy->next;
		}
	}
	void copyRandom(Node* head)
	{
		if (!head) return;
		Node* pos = head;
		while (pos)
		{
			// ����a -> a' -> b -> b' -> c -> c'
			// ���� a -> random���ڣ��� a' -> random һ������ a -> random -> next
			// ���� a -> random�����ڣ��� a' -> random == nullptr
			Node* copy = pos->next;
			Node* oldRandom = pos->random;
			if (oldRandom) copy->random = oldRandom->next;
			else copy->random = nullptr;
			pos = copy->next;
		}
	}
	Node* getCopy(Node* head)
	{
		if (!head) return head;
		Node* pos = head;
		Node* copy = pos->next;
		Node* newHead = copy;
		while (pos)
		{
			// ��ԭ�����븴�Ƴ���������ȡ���������������������ظ��Ƴ�������
			pos->next = copy->next;
			pos = pos->next;
			if (pos) copy->next = pos->next;
			copy = copy->next;
		}
		return newHead;
	}
};

//��ָoffer147��������в�������
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;     //����һ��ѽ�ڵ���head�ڵ�֮ǰ��
		ListNode* lastSorted = head; //�������������򲿷ֵ����һ���ڵ�
		ListNode* cur = head->next;  //ά��curΪ������Ľڵ�

		while (cur != nullptr)
		{
			if (lastSorted->val <= cur->val)
			{
				lastSorted = lastSorted->next;
			}
			else
			{
				ListNode* prev = dummyHead;
				while (prev->next->val <= cur->val)
				{
					prev = prev->next;
				}
				lastSorted->next = cur->next;
				cur->next = prev->next;
				prev->next = cur;
			}
			cur = lastSorted->next;
		}
		return dummyHead->next;

	}
};