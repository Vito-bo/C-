//ÿ��һ��7-31
//1.���Ǿ���
class Solution {
public:
	//����2����̬�滮������˼ά��
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;
		int row = triangle.size();
		//�ӵ�����2�п�ʼ
		for (int i = row - 2; i >= 0; --i){
			for (int j = 0; j <= i; j++){
				//F(i,j)=min(F(i+1,j),F(i+1,j+1))+arr[i][j]
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};
//2.·������
class Solution {
public:
	//״̬��F(i,j):��(0,0)����(i,j)��·������
	//״̬ת�Ʒ��̣�F(i,j):F(i-1,j)+F(i,j-1)
	//��ʼ״̬:F(0,j)  F(i,0)  ·����������1
	//���ؽ����F(m-1,n-1)
	int uniquePaths(int m, int n) {
		// write code here
		if (m<1 || n<1)
			return 0;
		//��ʼ��������F(I,J)�ռ�
		vector<vector<int>> ret(m, vector<int>(n, 1));

		for (int i = 1; i<m; i++){
			for (int j = 1; j<n; j++){
				ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
			}
		}
		return ret[m - 1][n - 1];
	}
};

