class Solution {
private:
	int max(int a, int b){
		return (a>b)? a:b;
	}
public:
	int rob(vector<int>& nums) {
		//rob_current[i][0]	当考察到第i个房间且第i个房间rob 且第0个房间没有rob 所能达到的最大值
		//rob_current[i][1]	当考察到第i个房间且第i个房间rob 且第0个房间有rob 所能达到的最大值
  		//rob_not_current[i][0]     当考察到第i个房间且第i个房间不rob 且第0个房间没有rob 所能达到的最大值
  		//rob_not_current[i][1]     当考察到第i个房间且第i个房间不rob 且第0个房间有rob 所能达到的最大值
  		if (nums.size()<=1)
  			return (nums.size()==1)? nums[0] : 0 ;
  		vector<vector<int>> rob_current(nums.size(), vector<int>(2,0));
  		vector<vector<int>> rob_not_current(nums.size(), vector<int>(2,0));
  		rob_current[0][1] = nums[0];
  		for (int i=1;i<nums.size();i++){
  			rob_current[i][0] = max(rob_current[i][0], rob_not_current[i-1][0] + nums[i]);
  			rob_current[i][1] = max(rob_current[i][1], rob_not_current[i-1][1] + nums[i]);
  			rob_not_current[i][0] = max(rob_current[i-1][0], rob_not_current[i-1][0]);
  			rob_not_current[i][1] = max(rob_current[i-1][1], rob_not_current[i-1][1]);
  		}
  		int result=0;
  		result = max(result, rob_current[nums.size()-1][0]);
  		// 排除掉首位均rob的情况
  		result = max(result, rob_not_current[nums.size()-1][1]);
  		result = max(result, rob_not_current[nums.size()-1][0]);
  		return result;
	}
};