//ÿ��һ��8-3-̰���㷨

//1.ѡ������
void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
void selectSort(int* arr, int n){
	//i: δ�������ݵ���ʼλ��
	for (int i = 0; i < n; ++i)
	{
		int minIdx = i;
		//������δ���������������Сֵ������
		for (int j = i + 1; j < n; ++j){
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr, minIdx, i);
	}
}
//2.ƽ���ַ���
class Solution {
public:
	int balancedStringSplit(string s) {
		int cnt = 0;
		int balance = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == 'L')
				balance--;
			if (s[i] == 'R')
				balance++;
			if (balance == 0)
				cnt++;
		}
		return cnt;
	}
};
//3.���Ʊ�����ʱ��
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			int curProfit = prices[i] - prices[i - 1];
			if (curProfit > 0)
				ret += curProfit;
		}
		return ret;
	}
};
//4.��Ծ��Ϸ
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int rightmost = 0;
		for (int i = 0; i < n; ++i) {
			//������Ե��ﵱǰλ�ã���������
			if (i <= rightmost) {
				//ÿ�θ�������λ��
				rightmost = max(rightmost, i + nums[i]);
				//������Ե������һ��λ�ã���ֱ�ӷ���
				if (rightmost >= n - 1) {
					return true;
				}
			}
		}
		return false;
	}
};