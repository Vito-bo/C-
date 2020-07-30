//��̬�滮�㷨ר��
//���ص㣺
//1.��ԭ��������ķֽ�ɼ������Ƶ�������
//2.���е������ⶼֻ��Ҫ���һ��
//3.�洢������Ľ�
//��Ҫ�أ�
//1.״̬����
//2.״̬���ת�Ʒ��̶���
//3.״̬�ĳ�ʼ��
//4.���ؽ��
//�����ʣ�
//״̬�Ķ��壬״̬ת�Ʒ��̵Ķ���

//1.Fibonacci
//˼·1���ݹ�
class Solution{
public:
	int Fibonacci(int n){
		// ��ʼֵ
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// F(n)=F(n-1)+F(n-2)
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}
};
//˼·2
//��̬�滮
class Solution2{
public:
	int Fibonacci(int n){
		// ��ʼֵ
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// ����һ�����飬����������Ľ⣬��ĿҪ��ӵ�0�ʼ
		int* record = new int[n + 1];
		record[0] = 0;
		record[1] = 1;
		for (int i = 2; i <= n; i++){
			// F(n)=F(n-1)+F(n-2)
			record[i] = record[i - 1] + record[i - 2];
		}
		return record[n];
		delete[] record;
	}
};
class Solution3{
public:
	int Fibonacci(int n){
		// ��ʼֵ
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		int fn1 = 1;
		int fn2 = 1;
		int result = 0;
		for (int i = 3; i <= n; i++){
			// F(n)=F(n-1)+F(n-2)
			result = fn2 + fn1;
			// ����ֵ
			fn1 = fn2;
			fn2 = result;
		}
		return result;
	}
};

//2.�ַ����ָ�
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> can_break(s.size() + 1, false);
		//��ʼ��F(0)=true;
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				//F(i):true{j<i&&F[j]&&substr[j+1,i]���ڴʵ����ҵ�} or false
				//��j+1���ַ�������Ϊj
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};
//3.���Ǿ���
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		if (triangle.empty())
			return 0;
		//F[i][j],F[0][0]��ʼ��
		vector<vector<int>> min_sum(triangle);
		int line = triangle.size();
		for (int i = 1; i<line; i++){
			for (int j = 0; j <= i; j++){
				//������߽���ұ߽�
				if (j == 0){
					min_sum[i][j] = min_sum[i - 1][j];
				}
				else if (i == j){
					min_sum[i][j] = min_sum[i - 1][j - 1];
				}
				else{
					min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]);
				}
				//F(i,j)=min(F(i-1,j-1),F(i-1,j))+triangle[i][j]
				min_sum[i][j] = min_sum[i][j] + triangle[i][j];
			}
		}
		int result = min_sum[line - 1][0];
		//min(F(n-1,i))
		for (int i = 1; i<line; i++){
			result = min(min_sum[line - 1][i], result);
		}
		return result;
	}
};
