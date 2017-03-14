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
	vector<int> LeftValue;
	void DiscoverRoot(TreeNode* root, int Depth){
		if (LeftValue.size() < Depth)
			LeftValue.push_back(root->val);
		else
			LeftValue[Depth-1] = root->val;
		if (root->right!=NULL)
			DiscoverRoot(root->right, Depth+1);
		if (root->left!=NULL)
			DiscoverRoot(root->left, Depth+1);
	}
public:
	int findBottomLeftValue(TreeNode* root) {
		DiscoverRoot(root, 1);
		return LeftValue[LeftValue.size()-1];
	}
};