class Solution {
private:
	int min(int a, int b){
		return (a<b)?a:b;
	}
	int max(int a, int b){
		return (a>b)?a:b;
	}
	bool findTarget(vector<int>& nums, int left, int right, int target) {
		int middle;
		middle = (left+right)/2;
		if (nums[left] == target)
			return true;
		if (nums[right] == target)
			return true;
		if (nums[middle] == target)
			return true;
		if (left==right || left == middle){
			return false;
		}

		// small = medium = large
		//	这里用了一个trick的方法
		//	如果left middle right的nums中有任意两个相等 则左右分别递归（因为理论上左右子树都有可能）
		if (nums[left] == nums[middle] || nums[middle] == nums[right])
			return findTarget(nums, left, middle,target) || findTarget(nums, middle, right, target);
		
		// small, medium, large
		if (nums[left] <= nums[middle] && nums[middle] <= nums[right]){
			if (nums[middle] < target)
				return findTarget(nums, middle, right, target);
			if (nums[middle] > target)
				return findTarget(nums, left, middle, target);
		}
		// large, medium, small
		if (nums[left] >= nums[middle] && nums[middle] >= nums[right]){
			if (nums[middle] > target)
				return findTarget(nums, middle, right, target);
			if (nums[middle] < target)
				return findTarget(nums, left, middle, target);	
		}
		// large,  small, medium
		if (nums[left] >= nums[right] && nums[right] >= nums[middle]){
			if (nums[middle] < target && target < nums[right])
				return findTarget(nums, middle, right, target);
			else
				return findTarget(nums, left, middle, target);	
		}
		// medium, large, small
		if (nums[left] >= nums[right] && nums[middle] >= nums[left]) {
			if (nums[left] < target && target < nums[middle])
				return findTarget(nums, left, middle, target);
			else
				return findTarget(nums, middle, right, target);
		}

		return -1;
	}
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size()==0)
			return false;
		return findTarget(nums, 0, nums.size()-1, target);
	}
};