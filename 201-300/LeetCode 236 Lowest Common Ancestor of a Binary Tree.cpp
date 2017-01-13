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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 依旧是暴力的解法
		// 看当前的root 左右两边有没有分开的p和q
		if (root==NULL || root==p || root==q)
			return root;
		TreeNode * leftNode, * rightNode;
		leftNode = lowestCommonAncestor(root->left, p,q);
		rightNode = lowestCommonAncestor(root->right,p,q);
		if (leftNode!=NULL && rightNode!=NULL)
			return root;
		if (leftNode!=NULL && rightNode==NULL)
			return leftNode;
		if (leftNode==NULL && rightNode!=NULL)
			return rightNode;
		// 如果没有祖先 即左右搜索结果都是NULL 则需要返回NULL
		if (leftNode==NULL && rightNode==NULL)
			return NULL;
		return root;
	}
};