//ÿ��һ�� �����㷨
//1.3���˿��Ʒֱ�ŵ�3��������ȥ����ÿ������ֻ�ܷ�һ���ƣ�һ���ж����ֲ�ͬ�ķŷ���
#include <vector>
#include <iostream>
using namespace std;
void Dfs(int index, int n, vector<int>& boxs, vector<int>& book)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; i++)
			cout << boxs[i] << " ";
		cout << endl;
		return; //���ϻ���
	}
	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0) //��i������������
		{
			boxs[index] = i;
			book[i] = 1; //���ڵ�i�����Ѿ�������
			//������һ������
			Dfs(index + 1, n, boxs, book);
			//����һ�����ӻ��˵���ǰ���ӣ�ȡ����ǰ���ӵ��ƣ�
			//���Է��������ơ�
			book[i] = 0;
		}
	}
}
int main()
{
	int n;
	vector<int> boxs;
	vector<int> books;
	cin >> n;
	boxs.resize(n + 1, 0);
	books.resize(n + 1, 0);
	Dfs(1, n, boxs, books);
	return 0;
}

//2.Ա������Ҫ��
class Solution {
public:
	int DFS(unordered_map<int, Employee*>& info, int id)
	{
		int curImpo = info[id]->importance;
		for (const auto& sid : info[id]->subordinates)
		{
			curImpo += DFS(info, sid);
		}
		return curImpo;
	}
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty())
			return 0;
		unordered_map<int, Employee*> info;
		for (const auto& e : employees)
		{
			info[e->id] = e;
		}
		return DFS(info, id);
	}
};

//3.ͼ����Ⱦ
#include <vector>
#include <iostream>
using namespace std;
//�ĸ������λ�ø��£�˳ʱ�����
int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book,
		int sr, int sc, int oldColor, int newColor)
	{
		//����ǰ�߼����޸���ɫ�����ұ���Ѿ��޸Ĺ���
		image[sr][sc] = newColor;
		book[sr][sc] = 1;
		//����ÿһ�ֿ��ܣ��ĸ�����
		for (int k = 0; k < 4; ++k)
		{
			int newSr = sr + nextPosition[k][0];
			int newSc = sc + nextPosition[k][1];
			//�ж���λ���Ƿ�Խ��
			if (newSr >= row || newSr < 0
				|| newSc >= col || newSc < 0)
				continue;
			//�����ɫ����Ҫ�󣬲���֮ǰҲû����Ⱦ�����������Ⱦ
			if (image[newSr][newSc] == oldColor && book[newSr][newSc] == 0)
			{
				dfs(image, row, col, book, newSr, newSc, oldColor, newColor);
			}
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int
		newColor) {
		if (image.empty())
			return image;
		int row = image.size();
		int col = image[0].size();
		//�������
		vector<vector<int>> book;
		book.resize(row);
		for (int i = 0; i < row; ++i)
		{
			book[i].resize(col, 0);
		}
		//��ȡ�ɵ���ɫ
		int oldColor = image[sr][sc];
		dfs(image, row, col, book, sr, sc, oldColor, newColor);
		return image;
	}
};