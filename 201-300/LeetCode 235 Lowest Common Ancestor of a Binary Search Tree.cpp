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
		// 如果是随意的Tree求Lowest Common Ancestor的的时候，需要将两个端点中间的中序遍历结果中Depth最低的点求出来
		// 但当前是已经排序过的Binary Search Tree，则可以用比较trick的方式
		if (root==p || root==q)
			return root;
		if (q->val < root->val && p->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		return root;
	}
};