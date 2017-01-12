class Solution {
private:
	void rotateProcess(vector<int>& nums, int left, int right){
		int tmp;
		int length = right-left+1;
		for (int i=0;i<length/2;i++){
			tmp = nums[left+i];
			nums[left+i] = nums[right-i];
			nums[right-i] = tmp;
		}
	}
public:
    void rotate(vector<int>& nums, int k) {
        // For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
        // 1,2,3,4,5,6,7 -> 7,6,5,4,3,2,1
        // 7,6,5,4,3,2,1 -> [7,6,5],[4,3,2,1]
        // [7,6,5],[4,3,2,1] -> [5,6,7],[1,2,3,4]

        // hints: k might larger than nums's size
        k = k % nums.size();
    	rotateProcess(nums,0,nums.size()-1);
    	rotateProcess(nums,0,k-1);
    	rotateProcess(nums,k,nums.size()-1);
    }
};