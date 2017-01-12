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
	vector<int> rightSideViewVector;
private:
	int TreeHeight = 0;
private:
	void getHeight(TreeNode* root, int height){
		TreeHeight = max(TreeHeight, height);
		if (root->left!=NULL)
			getHeight(root->left, height+1);
		if (root->right!=NULL)
			getHeight(root->right, height+1);
	}
private:
	void preorderTravel(TreeNode *root, int height) {
		if (root->left!=NULL)
			preorderTravel(root->left, height+1);
		if (root->right!=NULL)
			preorderTravel(root->right, height+1);
		rightSideViewVector[height] = root->val;
	}
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
        	return rightSideViewVector;
        getHeight(root,1);
        for (int i=0;i<TreeHeight;i++)
        	rightSideViewVector.push_back(-1);
        preorderTravel(root,0);
        return rightSideViewVector;
    }
};