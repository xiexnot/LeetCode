/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <vector>

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	
private:
	vector<int> Order;
	
private:
	void goTreeNode(TreeNode* root) {
		if (root->left != NULL)
			goTreeNode(root->left);
		Order.push_back(root->val);
		if (root->right != NULL)
			goTreeNode(root->right);
	}
	
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	if (root!=NULL){
    		goTreeNode(root);	
		}
        return Order;
    }
    
};
