class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		for (int i=0;i<nums.size();i++)
			nums[i] = nums[i] % k;
		
	}
};