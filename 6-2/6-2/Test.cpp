
////6-2-1
//#include<iostream>
//#include<vector>
//using namespace std;
//// ����ţ�Ͳ���������ȫ������Ӧ���������������������
//// ���룺
//// 4
//// 1 3 2 3
//// �����2
//// ���룺
//// 6
//// 3 2 1 1 2 3
//// �����2
//int main()
//{
//	int n;
//	cin >> n;
//	// ע����������һ��ֵ���Ǵ���Խ�������ıȽϣ�����ο�����Ľ���˼·
//	vector<int> a;
//	a.resize(n + 1);
//	a[n] = 0;
//	//��������
//	int i = 0;
//	for (i = 0; i < n; ++i)
//		cin >> a[i];
//	i = 0;
//	int count = 0;
//	while (i < n)
//	{
//		// �ǵݼ�������
//		if (a[i] < a[i + 1])
//		{
//			while (i < n && a[i] <= a[i + 1])
//				i++;
//			count++;
//			i++;
//		} 
//		else if (a[i] == a[i + 1])
//			i++;
//		else // �ǵ���������
//		{
//			while (i < n && a[i] >= a[i + 1])
//			i++;
//			count++;
//			i++;
//		}
//	} 
//	cout << count << endl;
//	return 0;
//}

////6-2-2
////�ⷨһ
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string s;
//	// ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս�����
//	getline(cin, s);
//	// ��ת��������
//	reverse(s.begin(), s.end());
//	// ��ת����
//	auto start = s.begin();
//	while (start != s.end())
//	{
//		auto end = start;
//		while (end != s.end() && *end != ' ')
//			end++;
//		reverse(start, end);
//		if (end != s.end())
//			start = end + 1;
//		else
//			start = end;
//	} 
//	cout << s << endl;
//	return 0;
//}
//�ⷨ2
#include <iostream>
#include <string>
using namespace std;
// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
int main()
{
	string s1, s2;
	cin >> s1;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
