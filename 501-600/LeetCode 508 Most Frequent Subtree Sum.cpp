/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>

class Solution {
private:
	vector<int> TreeSum;
	vector<int> UniqueTreeSum;
	vector<int> UniqueTreeSumCount;
	vector<int> MaxTreeSumCount;
	int DiscoverTree(TreeNode* root){
		int currentSum = root->val;
		if (root->left!=NULL){
			currentSum = currentSum + DiscoverTree(root->left);
			
		}
		if (root->right!=NULL){
			currentSum = currentSum + DiscoverTree(root->right);
		}
		TreeSum.push_back(currentSum);
		return currentSum;
	}
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		if (root!=NULL)
			DiscoverTree(root);
		else
			return MaxTreeSumCount;
		sort(TreeSum.begin(), TreeSum.end());
		UniqueTreeSum.push_back(TreeSum[0]);
		UniqueTreeSumCount.push_back(1);
		for (int i=1;i< TreeSum.size();i++)
			if (TreeSum[i]!=TreeSum[i-1]){
				UniqueTreeSum.push_back(TreeSum[i]);
				UniqueTreeSumCount.push_back(1);
			}
			else
				UniqueTreeSumCount[UniqueTreeSumCount.size()-1] ++;
		
		int TargetTreeSumCount;
		TargetTreeSumCount = UniqueTreeSumCount[0];
		for (int i=1;i<UniqueTreeSumCount.size();i++)
			TargetTreeSumCount = max(TargetTreeSumCount, UniqueTreeSumCount[i]);
		
		for (int i=0;i<UniqueTreeSumCount.size();i++)
			if (TargetTreeSumCount == UniqueTreeSumCount[i])
				MaxTreeSumCount.push_back(UniqueTreeSum[i]);
		
		return MaxTreeSumCount;	
	}
};