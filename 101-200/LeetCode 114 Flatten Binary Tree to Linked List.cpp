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
	TreeNode* getRightChild(TreeNode* root){
		if (root->right == NULL)
			return root;
		else
			return getRightChild(root->right);
	}
private:
	void getFlatten(TreeNode* root) {
		TreeNode* rightNode;
		if (root->left == NULL){
			if (root->right != NULL)
				getFlatten(root->right);
		}
		else{
			rightNode = getRightChild(root->left);
			rightNode->right = root->right;
			root->right = root->left;
			root->left = NULL;
			getFlatten(root->right);
		}
	}
public:
    void flatten(TreeNode* root) {
        if (root==NULL)
        	return ;
        getFlatten(root);
    }
};
