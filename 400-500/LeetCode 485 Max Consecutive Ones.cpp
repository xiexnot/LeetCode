#include <algorithm>

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.size()==0)
			return 0;
		int count, result;
		count = nums[0];
		result = count;
		for (int i=1;i<nums.size();i++){
			if (nums[i] == nums[i-1] && nums[i] == 1){
				count ++;
				result = max(result, count);
				continue;
			}
			if (nums[i] == 1 && nums[i] != nums[i-1]){
				count = 1;
				result = max(result, count);
				continue;
			}
		}
		return result;
	}
};