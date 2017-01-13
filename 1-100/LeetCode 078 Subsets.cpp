class Solution {
private:
	vector<bool> currentSelection;
	vector<vector<int>> subsetResult;
private:
	void search(vector<int>& nums, int x){
		if (x>=nums.size()){
			vector<int> currentSet;
			for (int i=0;i<nums.size();i++)
				if (currentSelection[i])
					currentSet.push_back(nums[i]);
			subsetResult.push_back(currentSet);
			return ;
		}
		currentSelection[x] = true;
		search(nums, x+1);
		currentSelection[x] = false;
		search(nums, x+1);
	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	for (int i=0;i<nums.size();i++)
    		currentSelection.push_back(false);
    	search(nums, 0);
    	return subsetResult;
    }
};