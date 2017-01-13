class Solution {
public:
	vector<int> grayCode(int n) {
		//	n=k时的Gray Code，相当于n=k-1时的Gray Code的逆序 加上 1<<k。
		vector<int> result;      
		result.push_back(0);  
		for(int i=0; i< n; i++)  
		{  
			int highestBit = 1<<i;  
			int len = result.size();  
			for(int i = len-1; i>=0; i--)  
				result.push_back(highestBit + result[i]);
		}  
		return result;
	}
};