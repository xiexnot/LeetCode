class Solution {
private:
	int max(int a, int b){
		return (a>b)? a:b;
	}
public:
    int rob(vector<int>& nums) {
  		//rob_current[i]	当考察到第i个房间且第i个房间rob所能达到的最大值
  		//rob_not_current[i]      当考察到第i个房间且第i个房间不rob所能达到的最大值
  		if (nums.size()<=1)
  			return (nums.size()==1)? nums[0] : 0 ;
  		vector<int> rob_current(nums.size(),0);
  		vector<int> rob_not_current(nums.size(),0);
  		rob_current[0] = nums[0];
  		for (int i=1;i<nums.size();i++){
  			rob_current[i] = max(rob_current[i], rob_not_current[i-1] + nums[i]);
  			rob_not_current[i] = max(rob_current[i-1], rob_not_current[i-1]);
  		}
  		return max(rob_not_current[nums.size()-1], rob_current[nums.size()-1]);
    }
};