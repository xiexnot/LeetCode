#include <algorithm>

class Solution {
private:
	int get(vector<int> &factor){
		int result = 1;
		result = result * pow(2,factor[0]);
		result = result * pow(3,factor[1]);
		result = result * pow(5,factor[2]);
		return result;
	}
	vector<int> Ugly;
	int UglySize = 0;
	vector<int> factor = {0,0,0};

	void search(int factorSize){
		for (int i=0;i<=factorSize;i++)
			for (int j=0;j<=factorSize-i;j++){
				factor[0] = i;
				factor[1] = j;
				factor[2] = factorSize - i - j;
				int newUglyNumber = get(factor);
				if (newUglyNumber>=0)
				    Ugly.push_back(newUglyNumber);
			}
	}

public:
	int nthUglyNumber(int n) {

		// 提供一个比我当前AC的算法看起来更优美的构造法 http://www.cnblogs.com/grandyang/p/4743837.html
		Ugly.push_back(1);
		int factorSize = 0;
		while (Ugly.size()<1690){
			factorSize ++;
			search(factorSize);
		}
		sort(Ugly.begin(), Ugly.end());
		return Ugly[n-1];
	}
};