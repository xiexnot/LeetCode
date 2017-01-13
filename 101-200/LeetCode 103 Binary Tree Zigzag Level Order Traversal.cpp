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
	void goTreeNode(TreeNode* root, int Depth) {
		if (zigzagOrder.size() < Depth){
			vector<int> newRow;
			zigzagOrder.push_back(newRow);
		}
		zigzagOrder[Depth-1].push_back(root->val);
		if (root->left != NULL)
			goTreeNode(root->left, 1 + Depth);
		if (root->right != NULL)
			goTreeNode(root->right, 1 + Depth);
	}
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	int tmp;
    	if (root!=NULL){
        	goTreeNode(root, 1);
        	for (int i=0;i<zigzagOrder.size();i++)
	        	if (i&1){
	        		//cout << i << endl;
	        		for (int item=0;item<zigzagOrder[i].size()/2;item++){
	        			tmp = zigzagOrder[i][item];
	        			zigzagOrder[i][item] = zigzagOrder[i][zigzagOrder[i].size()-1-item];
	        			zigzagOrder[i][zigzagOrder[i].size()-1-item] = tmp;
	        		}
	        	}
    
	     }
	     return zigzagOrder;
    }
};
