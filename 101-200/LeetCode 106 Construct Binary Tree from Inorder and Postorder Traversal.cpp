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
	TreeNode* buildTreeNode(vector<int>& inorder, vector<int>& postorder, int inorderStartIndex, int inorderEndingIndex, int postorderStartIndex, int postorderEndingIndex) {
		int rootValue = postorder[postorderEndingIndex];
		TreeNode* newNode = new TreeNode(rootValue);	
		int leftLength, rightLength, inorderRootPosition;

		for (int i=inorderStartIndex;i<=inorderEndingIndex;i++)
			if (inorder[i] == rootValue){
				inorderRootPosition = i;
				break;
			}
		leftLength = inorderRootPosition - inorderStartIndex;
		rightLength = inorderEndingIndex - inorderRootPosition;
		if (leftLength!=0)
			newNode->left = buildTreeNode(inorder, postorder, inorderStartIndex , inorderStartIndex + leftLength - 1, postorderStartIndex , postorderStartIndex + leftLength - 1);
		if (rightLength!=0)
			newNode->right = buildTreeNode(inorder, postorder, inorderRootPosition + 1, inorderRootPosition + 1 + rightLength - 1, postorderStartIndex + leftLength, postorderEndingIndex - 1);
		return newNode;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		//	有中序后序 构建tree
		if (inorder.size()==0)
			return NULL;
		return buildTreeNode(inorder, postorder, 0, inorder.size()-1, 0 , postorder.size()-1);
	}
};