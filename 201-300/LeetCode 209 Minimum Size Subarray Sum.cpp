class Solution {
private:
	bool isPossiable(std::vector<int> &nums, int length, int target) {
		int Sum = 0;
		int left = 0;
		int right = left + length - 1;
		for (int i=left;i<=right;i++)
			Sum += nums[i];
		if (Sum >= target)
			return true;
		
		for (int left=1;left<nums.size();left++){
			right = left + length - 1;
			if (right >= nums.size())
				return false;
			Sum = Sum - nums[left-1] + nums[right];
			if (Sum >= target)
				return true;
		}
		return false;
	}
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		// 输出0的情况
		int Sum = 0;
		for (int i=0;i<nums.size();i++)
			Sum = Sum + nums[i];
		if (Sum < s)
			return 0;

		//二分最佳答案 进行可行性判断 nlogn
		int left = 1;
		int right = nums.size();
		int middle;
		while (left<right){
			middle = (left+right)/2;
			if (isPossiable(nums, middle, s))
				right = middle;
			else
				left = middle+1;
		}
		return left;
	}
};