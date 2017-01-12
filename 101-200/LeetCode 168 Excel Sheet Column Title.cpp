class Solution {
public:
	string convertToTitle(int n) {
		vector<int> TitleNum;
		string Title = "";
		char currentChar;
		//	本题边角情况有点多，送了好多次WA...
		//	主要是Z-AA以及ZZ-AAA这类的情况 相当于每次进位 A0或者A00都被吃掉了（如果A为1的话）
		//	故每次进位之后都要跳过A0..0的情况
		while (n>0){
		    n = n - 1;
			TitleNum.push_back(n%26);
			n /= 26;
		}
		if (TitleNum.size()==0)
			TitleNum.push_back(0);
		for (int i=TitleNum.size()-1;i>=1;i--){
			cout << TitleNum[i] << endl;
			currentChar = TitleNum[i]  + 'A';
			Title = Title + currentChar;
		}
		cout << TitleNum[0] << endl;
		currentChar = TitleNum[0] +  'A';
		Title = Title + currentChar;
		return Title;
	}
};