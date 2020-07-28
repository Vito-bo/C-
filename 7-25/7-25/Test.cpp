//ÿ��һ��7-25
//1.������ֵ����
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		vector<int> mxL(n, 0);//��¼iλ������ֵ
		vector<int> mxR(n, 0);//��¼iλ�Ҳ����ֵ
		int ma = INT_MIN;
		for (int i = 0; i<n; i++){//���
			if (i == 0)
				mxL[i] = A[i];
			else
				mxL[i] = max(A[i], mxL[i - 1]); // �� i λ�������ֵ���� i - 1 λ���ֵ�� i ��ֵ�Ľϴ�ֵ
		} 
		for (int i = n - 1; i >= 0; i--){//�Ҳ�
			if (i == n - 1)
				mxR[i] = A[i];
			else
				mxR[i] = max(A[i], mxR[i + 1]);
		} 
			// ������������Ϊ[2, 7, 3, 1, 1]
			// mxL �е�ֵΪ: [2,7,7,7,7]
			// mxR �е�ֵΪ: [7,7,3,1,1]
			int res = INT_MIN;
		// ��������ѭ����������������ֵ����.
			for (int i = 0; i<n - 1; i++){//���
				res = max(res, abs(mxL[i] - mxR[i + 1]));
			} 
			return res;
	}
};
//2.˳ʱ���ӡ����
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		int x1 = 0, y1 = 0; //���Ͻ�����
		int x2 = n - 1, y2 = m - 1; //���½�����
		// �����������ʾ��һ������(�ʼ�ľ���)
		// Ȼ����Ҫ���ӡ����Ȧ������.
		// ��ӡ���֮��, ��С���εĴ�С.
		while (x1 <= x2 && y1 <= y2){
			for (int j = y1; j <= y2; ++j)
				ret.push_back(mat[x1][j]);
			for (int i = x1 + 1; i < x2; ++i)
				ret.push_back(mat[i][y2]);
			for (int j = y2; x1 < x2 && j >= y1; --j) //x1 < x2��ֻ���ڲ��ǵ�һ�ĺ���ʱ��ִ�����ѭ��
				ret.push_back(mat[x2][j]);
			for (int i = x2 - 1; y1 < y2 && i > x1; --i)//y1 < y2��ֻ���ڲ��ǵ�һ������ʱ��ִ�����ѭ��
				ret.push_back(mat[i][y1]);
			x1++; y1++;
			x2--; y2--;
		} 
		return ret;
	}
};
