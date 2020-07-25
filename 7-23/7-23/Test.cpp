//ÿ��һ��7-23
//1.�����г��ִ�������һ�������
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		if (n == 0)
			return 0;
		int num = numbers[0], count = 1;
		for (int i = 1; i<n; i++){
			if (numbers[i] == num){
				count++;
			}
			else{
				count--;
			}
			if (count == 0){
				num = numbers[i];
				count = 1;
			}
		}
		//��������Ĳ����Ѿ��ҵ�num��
		//����ȷ��numȷʵ�ǳ��ִ�������һ��
		count = 0;
		for (int i = 0; i<n; i++){
			if (numbers[i] == num)
				count++;
		}
		if (count>n / 2)
			return num;
		return 0;
	}
};
//2.�򵥴����¼
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string getFileName(string path){
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
} 
string modifyName(string name){
	if (name.size() > 16){
		name = name.substr(name.size() - 16);
	} 
	return name;
} 
struct ErrRecord{
	string file;
	int lineNo;
	int count;
	ErrRecord(string file, int lineNo){
		this->file = file;
		this->lineNo = lineNo;
		count = 1;
	}
	// ������Ҫ���в���, �����ȶ�������������¼ʲô��������.
	bool operator==(const ErrRecord & a){
		return (file == a.file) && (lineNo == a.lineNo);
	}
};
int main(){
	string file;
	int lineNo;
	vector<ErrRecord> myvec;
	while (cin >> file >> lineNo) {
		ErrRecord record(getFileName(file), lineNo);
		auto res = find(myvec.begin(), myvec.end(), record);
		if (res == myvec.end()){
			myvec.push_back(record);
		}
		else {
			res->count++;
		}
	} 
	int count = 0;
	for (auto item : myvec){
		if (count + 8 >= myvec.size()){
			cout << modifyName(item.file) << " " << item.lineNo << " "
				<< item.count << endl;
		} 
		count++;
	} 
	return 0;
}