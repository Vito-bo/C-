////6-3-1 ��������ַ���
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	string str, res, cur;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++)
//	{
//		// ����+=��cur
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			cur += str[i];
//		} 
//		else
//		{
//			// �ҳ��������ַ�����������ַ���
//			if (res.size() < cur.size())
//			res = cur;
//			else
//				cur.clear();
//		}
//	} 
//	cout << res;
//	return 0;
//}

//6-3-2 �����г��ִ�������һ�������
//�ⷨһ
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
		if (numbers.empty()) return 0;
		sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int middle = numbers[numbers.size() / 2];
		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		} 
	    return(count>numbers.size() / 2) ? middle : 0;
	}
};

//�ⷨ��
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;
		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int times = 1; // ����
		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
                times = 1;
} 
			else if (numbers[i] == result)
			{
				++times; // ��ͬ���1
			} 
			else
			{
				--times; // ��ͬ���1
			}
		} 
		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result) ++times;
		} 
		return(times > numbers.size() / 2) ? result : 0��
};




