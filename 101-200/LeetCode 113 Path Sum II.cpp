/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	vector<vector<int>> resultPath;
	int sumTarget, sumCurrent;
	vector<int> currentPath;

private:
	void pathTravel(TreeNode* root) {
		currentPath.push_back(root->val);
		sumCurrent = sumCurrent + root->val;
		if (root->left == NULL && root->right==NULL){
			if (sumCurrent == sumTarget)
				resultPath.push_back(currentPath);
			sumCurrent = sumCurrent - root->val;
			currentPath.pop_back();
			return ;
		}

		if (root->left!=NULL)
			pathTravel(root->left);
		if (root->right!=NULL)
			pathTravel(root->right);
		sumCurrent = sumCurrent - root->val;
		currentPath.pop_back();
		return ;
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		sumCurrent = 0;
		sumTarget = sum;
		if (root!=NULL)
			pathTravel(root);
		return resultPath;
	}
};