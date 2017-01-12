#include <algorithm>

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int n_benchmark = nums.size() / 2;
		int count = 1;
		for (int i=1;i<nums.size();i++){
			if (nums[i] == nums[i-1])
				count ++;
			if (count > n_benchmark)
				return nums[i];
		}
		return nums[0];
	}
};