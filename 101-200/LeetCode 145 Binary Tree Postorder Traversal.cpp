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
	vector<int> postorderTree;
private:
	void postorderTraversalProcess(TreeNode* root) {
		
		if (root->left!=NULL)
			postorderTraversalProcess(root->left);
		if (root->right!=NULL)
			postorderTraversalProcess(root->right);
		postorderTree.push_back(root->val);
	}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root!=NULL)
    		postorderTraversalProcess(root);
     	 return postorderTree;
    }
};