//list�Ľ��ܼ�ʹ��
//list�ײ���˫������ṹ
//forward_list�ǵ�����ֻ�ܳ�ǰ����

#include <iostream>
#include <list>
#include <vector>
using namespace std;
//
////1.list�Ĺ���
//int main()
//{
//	list<int> l1;        //����յ�l1
//	list<int> l2(4, 100);//l2�з�4��ֵΪ100��Ԫ��
//	list<int> l3(l2.begin(), l2.end());//��l2��[begin(),l2.end()]����ҿ����乹��l3
//	list<int> l4(l3);    //��l3��������l4
//
//	//������Ϊ����������l5
//	int arr[] = { 16, 17, 5, 19 };
//	list<int> l5(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//�õ�������ʽ��ӡl5�е�Ԫ��
//	list<int>::iterator it = l5.begin();
//	while (it != l5.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//C++11��Χfor�ķ�ʽ����
//	for (auto& e : l5){
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

////list iterator��ʹ��
////begin��endΪ������������Ե�����ִ��++����������������ƶ�
////rbegin��rendΪ������������Ե���������++��������������ǰ�ƶ�
//void print_list(const list<int>& l)
//{
//	// ע��������õ���list�� begin() const������list��const_iterator����
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//		 //*it = 10; //���벻ͨ��
//	}
//	cout << endl;
//}
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	//ʹ����������������ӡlist�е�Ԫ��
//	list<int>::iterator it = l.begin();
//	while (it != l.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//ʹ�÷����������ӡList�е�Ԫ��
//	list<int>::reverse_iterator rit = l.rbegin();
//	while (rit != l.rend()){
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	print_list(l);
//	cout << l.front() << endl;
//	cout << l.back() << endl;
//	
//	l.push_front(3);
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//	l.pop_front();
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//
//	l.push_back(7);
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//	l.pop_back();
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

////list modifiers
//void PrintList(list<int>& l)
//{
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int  main()
//{
//	//int arr1[] = { 1, 2, 3 };
//	//list<int> L(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
//
//	////��ȡ�����еĵڶ����ڵ�
//	//auto pos = ++L.begin();
//	//cout << *pos << endl;
//	////��posλ��ǰ����ֵΪ4��Ԫ��
//	//L.insert(pos, 4);
//	//PrintList(L);
//
//	////��posǰ����5��ֵΪ5��Ԫ��
//	//L.insert(pos, 5, 5);
//	//PrintList(L);
//
//	////��posǰ����[v.begin(),v.end()]�����е�Ԫ��
//	//vector<int> v{ 7, 8, 9 };
//	//L.insert(pos, v.begin(), v.end());
//	//PrintList(L);
//
//	////ɾ��posλ���ϵ�Ԫ��
//	//L.erase(pos);
//	//PrintList(L);
//
//	////ɾ��list�е�[begin,end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
//	//L.erase(L.begin(), L.end());
//	//PrintList(L);
//
//	//������������list
//	int arr[] = { 1, 2, 3 };
//	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	PrintList(l1);
//	
//	//����l1��l2�е�Ԫ��
//	list<int> l2;
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	//��l2�е�Ԫ�����
//	l2.clear();
//	cout << l2.size() << endl;
//
//	return 0;
//}

//list�ĵ�����ʧЧ
void TestListIterator1()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		l.erase(it);
		++it;
	}
}
// ����
void TestListIterator()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}

int main()
{
	//TestListIterator1();
	TestListIterator();
	return 0;
}
