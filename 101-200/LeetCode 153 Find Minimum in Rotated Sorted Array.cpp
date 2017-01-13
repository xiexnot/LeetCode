class Solution {
private:
	int min(int a, int b){
		return (a<b)?a:b;
	}
private:
	int findMinElement(vector<int>& nums, int left, int right){
		int middle;
		middle = (left+right) / 2;
		//cout << left<< " " << middle <<" "<< right << endl;
		if (left==right || left == middle)
			return min(nums[left], nums[right]);
		// small, medium, large
		if (nums[left] < nums[middle] && nums[middle] < nums[right])
			return nums[left];
		// large, medium, small
		if (nums[left] > nums[middle] && nums[middle] > nums[right])
			return nums[right];
		// large,  small, medium
		if (nums[left] > nums[right] && nums[right] > nums[middle])
			return findMinElement(nums, left, middle);
		// medium, large, small
		if (nums[left] > nums[right] && nums[middle] > nums[left])
			return findMinElement(nums, middle, right);
		return 0;
	}
public:
    int findMin(vector<int>& nums) {
    	if (nums.size()==1){
    		return nums[0];
    	}
    	if (nums.size()==2){
    		return min(nums[0], nums[1]);
    	}
        return findMinElement(nums,0,nums.size()-1);
    }
};