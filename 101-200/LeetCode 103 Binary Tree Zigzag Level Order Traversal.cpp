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
	vector<vector<int>> zigzagOrder;
	void goTreeNode(TreeNode* root, bool binaryDepth) {
		if binar
		if (root->left != NULL)
			goTreeNode(root->left, 1 + binaryDepth);
		if (root->right != NULL)
			goTreeNode(root->right, 1 + binaryDepth);
		
	}
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	if (root!=NULL)
        	goTreeNode(root, 1);
        return zigzagOrder;
    }
};
