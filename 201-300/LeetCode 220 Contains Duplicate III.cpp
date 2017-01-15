class Solution {
private:
    int min(int a,int b){
        return (a<b)?a:b;
    }
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		// reference:http://bookshadow.com/weblog/2015/06/03/leetcode-contains-duplicate-iii/
		// 先考虑光是用sliding window的做法 o(nk)
		
		// 事实证明没办法用o(nk)的做法AC 极限数据n=20000 k=10000

        long dist;
		int index=0;
		
		for (int i=0;i<min(k,nums.size());i++)
			for (int j=index;j<i;j++){
			    dist = (long) nums[i] - (long) nums[j];
				if (dist >= -t && dist <=t)
					return true;
			}

		for (int i=min(k,nums.size());i<nums.size();i++){
			for (int j=index;j<i;j++){
			    dist = (long) nums[i] - (long) nums[j];
			    if (dist >= -t && dist <=t)
					return true;
			}
			index++;
		}

		return false;
	}
};