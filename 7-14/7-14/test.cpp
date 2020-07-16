//ÿ��һ��7-14
//1.�����
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct pos { int x, y; };
int bfs(vector<vector<char> > & map, vector<vector<bool> > & visit, pos & start)
{
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	queue<pos> que;
	int count = 0;
	int m = map.size(), n = map[0].size();
	que.push(start);
	visit[start.x][start.y] = true; ++count;
	while (!que.empty())
	{
		pos cur = que.front(), next;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
				++count;
			}
		}
	} 
	return count;
} 
int main()
{
	int m, n;
	while (cin >> m >> n && (m*n))
	{
		pos start;
		vector<vector<char> > map(m, vector<char>(n));
		vector<vector<bool> > visit(m, vector<bool>(n));
		for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			visit[i][j] = false;
			cin >> map[i][j];
			if (map[i][j] == '@')
				start.x = i, start.y = j;
		}
		cout << bfs(map, visit, start) << endl;
	} 
	return 0;
}
//2.Ģ����
#include<iostream>
#include <iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k){
		// ��������Ģ����ͼ
		vector<vector<int> > table((n + 1), vector<int>(m + 1));
		// ����Ģ����ͼ
		int x, y;
		for (int i = 0; i < k; i++){
			cin >> x >> y;
			table[x][y] = 1;
		} 
		// P[i][j]��ʾ������Ģ���ߵ�i��j�ĸ���
			vector<vector<double> > P((n + 1), vector<double>(m + 1));
		P[1][1] = 1.0; //������Ϊ1
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++)
			{
				if (!(i == 1 && j == 1)){ //�������
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + P[i][j - 1] * (i == n ? 1 : 0.5); //�߽��ʱ�򣬸���Ϊ1
					if (table[i][j] == 1) P[i][j] = 0; //����õ���Ģ����������Ϊ0
				}
			}
		} 
		cout << fixed << setprecision(2) << P[n][m] << endl;
	}
}