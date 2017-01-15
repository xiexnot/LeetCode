class Solution {
private:
	vector<int> compute(string input, int left, int right){
		bool hasOperation=false;
		vector<int> result;
		vector<int> leftResult;
		vector<int> rightResult;
		string current;
		for(int i=left;i<=right;i++)
			if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
				hasOperation = true;
				leftResult = compute(input, left, i-1);
				rightResult = compute(input, i+1, right);
				for (int p=0;p<leftResult.size();p++)
					for (int q=0;q<rightResult.size();q++){
						if (input[i]=='+')
							result.push_back(leftResult[p]+rightResult[q]);
						if (input[i]=='-')
							result.push_back(leftResult[p]-rightResult[q]);
						if (input[i]=='*')
							result.push_back(leftResult[p]*rightResult[q]);
					}
			}
		if (!hasOperation){
			current = input.substr(left, right-left+1);
			result.push_back(stoi(current));
		}
		return result;
	}
public:
	vector<int> diffWaysToCompute(string input) {
		if (input.size()!=0)
			return compute(input, 0, input.size()-1);
		else
			return vector<int>(0);
	}
};