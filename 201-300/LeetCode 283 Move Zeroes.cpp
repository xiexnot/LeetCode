class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zero_index = -1;
		int i = 0, tmp;
		int hasExchange;
		// 在0后面找第一个非0进行交换
		while (i<nums.size()){
			if (nums[i] == 0){
				hasExchange = false;
				for (int j=i+1;j<nums.size();j++)
					if (nums[j]!=0){
						tmp = nums[i];
						nums[i] = nums[j];
						nums[j] = tmp;
						hasExchange = true;
						break;
					}
				if (!hasExchange)
					return ;
			}
			i++;
		}
		return ;
	}
};