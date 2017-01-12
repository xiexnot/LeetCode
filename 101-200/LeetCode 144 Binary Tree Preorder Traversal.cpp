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
	vector<int> preorderTree;
private:
	void preorderTraversalProcess(TreeNode* root) {
		preorderTree.push_back(root->val);
		if (root->left!=NULL)
			preorderTraversalProcess(root->left);
		if (root->right!=NULL)
			preorderTraversalProcess(root->right);
	}
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	if (root!=NULL)
    		preorderTraversalProcess(root);
     	 return preorderTree;
    }
};