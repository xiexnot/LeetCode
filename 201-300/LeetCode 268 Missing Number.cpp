#include <algorithm>

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		// xor运算
		// 第一遍是所有nums
		// 第二遍是从0到n
		// 两遍结果xor起来 最后就得到缺的数字
		int count = 0;
		for (int i=0;i<nums.size();i++)
			count = count ^ nums[i];
		for (int i=0;i<nums.size();i++)
			count = count ^ i;
		count = count ^ nums.size();
		return count;
	}
};