class Solution {
private:
	vector<int> UniqueNums;
	vector<int> UniqueNumsTimes;
	vector<vector<int>> subsetsResult;
	vector<int> currentNumsTimes;
	void search(int x){
		if (x>=UniqueNums.size()){
			// process
			vector<int> currentSet;
			for (int i=0;i<currentNumsTimes.size();i++)
				for (int j=0;j<currentNumsTimes[i];j++)
					currentSet.push_back(UniqueNums[i]);
			subsetsResult.push_back(currentSet);
			return ;
		}
		for (int i=0;i<=UniqueNumsTimes[x];i++){
			currentNumsTimes[x] = i;
			search(x+1);
		}
	}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        UniqueNums.push_back(nums[0]);
        UniqueNumsTimes.push_back(1);
        int UniqueNumsIndex = 0;
        for (int i=1;i<nums.size();i++)
        	if (nums[i] == UniqueNums[UniqueNumsIndex])
        		UniqueNumsTimes[UniqueNumsIndex] ++;
        	else{
        		UniqueNumsIndex ++;
        		UniqueNums.push_back(nums[i]);
        		UniqueNumsTimes.push_back(1);
        	}
        for (int i=0;i<UniqueNums.size();i++)
        	currentNumsTimes.push_back(0);
        search(0);
        return subsetsResult;
    }
};