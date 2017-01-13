#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//给定一个整型数组和一个整型数K，
		//找出是否存在两个不同的索引i和j，使得nums[i] = nums[j]，
		//并且它们之间的距离最大为K。
		unordered_map<int, int> hash;
		unordered_map<int, int>::const_iterator item;
        pair<int,int> new_item(0,0);
         
		for (int i=0;i<nums.size();i++){
			item = hash.find(nums[i]);
			if (item==hash.end()){
			    new_item.first = nums[i];
			    new_item.second = i;
			    hash.insert(new_item);
			}
			else{
				if (i - hash[nums[i]]<=k)
					return true;
				hash[nums[i]] = i;
			}
		}
		return false;
	}
};