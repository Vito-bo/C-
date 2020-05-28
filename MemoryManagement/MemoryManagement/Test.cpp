#include <iostream>
using namespace std;

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
//	// ������Ҫfree(p2)��
//	free(p3);
//}

//void Test()
//{
//	//��̬����һ��int���͵Ŀռ�
//	int* ptr1 = new int;
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr2 = new int(10);
//	//��̬����10��int���͵Ŀռ�
//	int* ptr3 = new int[10];
//
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//}
//new��delete�����Զ�i����
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test2()
{
	//���뵥��Test���͵Ŀռ�
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	//����10��Test���͵Ŀռ�
	Test* p2 = (Test*)malloc(sizeof(Test)* 4);
	free(p2);
}

void Test3()
{
	//���뵥��Test���͵Ķ���
	Test* p1 = new Test;

	//����10��Test���͵Ķ���
	Test* p2 = new Test[10];
	delete[] p2;
}
//�������Զ������͵Ŀռ�ʱ��new����ù��캯����delete�����������������malloc��free���ᡣ

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;
	void* operator new(size_t n)
	{ 
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0;
}