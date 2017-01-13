class Solution {
private:
	int min(int a, int b){
		return (a<b)? a:b;
	}
	int max(int a, int b){
		return (a>b)? a:b;
	}
public:
    int maxProduct(vector<int>& nums) {
  		vector<int> minProductVector(nums.size(),30000000);
  		vector<int> maxProductVector(nums.size(),-30000000);
  		if (nums.size()==1)
  			return nums[0];
  		if (nums[0] > 0){
  			maxProductVector[0] = nums[0];
  			minProductVector[0] = 0;
  		}
  		else{
  			minProductVector[0] = nums[0];
  			maxProductVector[0] = 0;
  		}
  			
  		for (int i=1;i<nums.size();i++)
  			if (nums[i] > 0){
  				maxProductVector[i] = max(nums[i], maxProductVector[i-1] * nums[i]);
  				minProductVector[i] = min(nums[i], minProductVector[i-1] * nums[i]);
  			}
  			else{
  				maxProductVector[i] = max(nums[i], minProductVector[i-1]*nums[i]);
  				minProductVector[i] = min(nums[i], maxProductVector[i-1]*nums[i]);
  			}
  		int result = -30000000;
  		for (int i=0;i<nums.size();i++){
  			result = max(result, maxProductVector[i]);
  		}
  		return result;

    }
};