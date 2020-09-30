
//9-30ˢ��

/*
//1.��ָoffer-10-II-������̨������
//����1
class Solution {
public:
	int numWays(int n) {
		if (n <= 1)
			return 1;
		if (n == 2)
			return 2;
		int f1 = 1;
		int f2 = 2;
		int res;
		while (n>2)
		{
			res = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = res;
			n--;
		}
		return res;
	}
};
//����2
class Solution {
public:
	int numWays(int n) {
		int a[101]={1,1};
		for(int i=2;i<=n;++i)
		{
			a[i] = (a[i-1]+a[i-2])%1000000007;
		}
		return a[n];
	}
};
*/

/*
//2.��ָoffer 11.��ת�������С����
//����1��������
class Solution {
public:
	int minArray(vector<int>& numbers) {
		int min = numbers[0];
		for (int i = 1; i<numbers.size(); ++i)
		{
			if (min >= numbers[i])
				min = numbers[i];
		}
		return min;
	}
};
//����2�����ַ�
class Solution {
public:
	int minArray(vector<int>& numbers) 
	{
		int i=0,j=numbers.size()-1;
		while(i<j)
		{
			int m=(i+j)/2;
			if(numbers[m] > numbers[j])
				i=m+1;
			else if(numbers[m] < numbers[j])
				j=m;
			else
				j--;
		}
		return numbers[i];
	}
};

*/

#if 0
//2.��ָoffer12-�����е�·��
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || word.empty())
			return false;
		for (int i = 0; i<board.size(); ++i)
		{
			//���ݷ��ݹ����
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (dfs(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
	//i,j:�ַ�����λ��  w:�ַ�������
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w)
	{
		//�������Խ�磬����ֵ��ƥ�䣬����false
		if (i<0 || i >= board.size() || j<0 || j >= board[0].size() || board[i][j] != word[w])
			return false;
		//����������ַ�����ƥ��ɹ�
		if (w == word.length() - 1)
			return true;
		char tmp = board[i][j];
		board[i][j] = '\0'; //����ǰԪ�ر��Ϊ'\0'����һ�������ܳ�����word�����Ԫ�أ�������ǰԪ�ز����ٲ���Ƚ�
		if (dfs(board, word, i - 1, j, w + 1)
			|| dfs(board, word, i + 1, j, w + 1)
			|| dfs(board, word, i, j - 1, w + 1)
			|| dfs(board, word, i, j + 1, w + 1))
		{
			//��ǰԪ�ص��������ң������ƥ�䵽�ģ�����true
			return true;
		}
		board[i][j] = tmp; //����ǰԪ�ػָ�����ֵ
		return false;
	}
};
#endif
/*

//4.��ָoffer05-�滻�ո�
class Solution {
public:
	string replaceSpace(string s)
	{
		int count = 0; // ͳ�ƿո�ĸ���
		int sOldSize = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				count++;
			}
		}
		// �����ַ���s�Ĵ�С���ո��滻Ϊ%20,��������λ��
		s.resize(s.size() + count * 2);
		int sNewSize = s.size();
		// �Ӻ���ǰ���ո��滻Ϊ"%20"
		for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--)
		{
			if (s[j] != ' ')
			{
				s[i] = s[j];
			}
			else
			{
				s[i] = '0';
				s[i - 1] = '2';
				s[i - 2] = '%';
				i -= 2;
			}
		}
		return s;
	}
};

*/