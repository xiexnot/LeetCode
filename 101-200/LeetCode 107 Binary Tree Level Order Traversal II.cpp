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
	vector<vector<int>> levelOrder;
	void goTreeNode(TreeNode* root, int Depth) {
		if (levelOrder.size() < Depth){
			vector<int> newRow;
			levelOrder.push_back(newRow);
		}
		levelOrder[Depth-1].push_back(root->val);
		if (root->left != NULL)
			goTreeNode(root->left, 1 + Depth);
		if (root->right != NULL)
			goTreeNode(root->right, 1 + Depth);
	}
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int tmp;
    	if (root!=NULL){
        	goTreeNode(root, 1);
        	// swap each content in levelOrder
        	for (int i=0;i<levelOrder.size()/2;i++)
        		levelOrder[i].swap(levelOrder[levelOrder.size()-1-i]);
	     }
	     return levelOrder;
    }
};