class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int startIndex, endingIndex;
		if (nums.size() == 0){
			return 0;
		}
		if (nums.size() == 1){
			return 0;
		}
		startIndex = 0;
		endingIndex = nums.size()-1;
		if (nums[startIndex]>nums[startIndex+1]){
			return startIndex;
		}
		if (nums[endingIndex-1] < nums[endingIndex]){
			return endingIndex;
		}
		int middleIndex;
		while (true){
			middleIndex = (startIndex + endingIndex) / 2;
			//cout << startIndex << " " << middleIndex << " " << endingIndex << endl;
			if (startIndex == middleIndex || endingIndex == middleIndex){
				// startIndex和endingIndex重合或只差1
				return nums[startIndex]<nums[endingIndex]? endingIndex : startIndex;
			}
			if (nums[middleIndex-1] <nums[middleIndex] && nums[middleIndex] > nums[middleIndex+1])
				return middleIndex;
			if (nums[middleIndex-1] < nums[middleIndex])
				startIndex = middleIndex;
			else
				endingIndex = middleIndex;
		}
	}
};