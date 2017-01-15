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
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> resultPaths;
		if (root==NULL)
			return resultPaths;
		if (root->left==NULL && root->right==NULL){
			string newString;
			newString = to_string(root->val);
			resultPaths.pushback(newString);
			return resultPaths;
		}
		vector<string> LeftPaths;
		vector<string> RightPaths;
		LeftPaths = binaryTreePaths(root->left);
		RightPaths = binaryTreePaths(root->right);
		resultPaths.insert(resultPaths.end(), LeftPaths.begin(), LeftPaths.end());
		resultPaths.insert(resultPaths.end(), RightPaths.begin(), RightPaths.end());
		for (int i=0;i<resultPaths.size();i++)
			resultPaths[i] = to_string(root->val) + "->" + resultPaths[i];
		return resultPaths;
	}
};