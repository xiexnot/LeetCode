class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	// 双指针指向头尾
    	// 如果大了 则尾指针前移 反之则头指针后移
    	vector<int> ResultVector;
    	int left, right;
    	left = 0;
    	right = numbers.size()-1;
    	while (true){
    		if (numbers[left] + numbers[right] == target)
    			break;
    		if (numbers[left] + numbers[right] < target)
    			left ++;
    		else
    			right --;
    	}
    	ResultVector.push_back(left+1);
    	ResultVector.push_back(right+1);
    	return ResultVector;
    }
};