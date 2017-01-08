/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 #include <iostream>
 #include <cmath>
 #include <stdio.h>
 
 struct TreeNode {
    	int val;
    	TreeNode *left;
    	TreeNode *right;
    	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

class Solution {
	
private:
	int totalSum;

private:
	int goPath(TreeNode* root, int currentSum){
		if (root->left == NULL && root->right == NULL){
			totalSum = totalSum + currentSum * 10 + root->val;
			return 0;
		}
		if (root->left != NULL){
			goPath(root->left, currentSum * 10 + root->val);		
		}
		if (root->right != NULL){
			goPath(root->right, currentSum * 10 + root->val);
		}
		return 0;		
	}
	
public:
    int sumNumbers(TreeNode* root) {
    	totalSum = 0;
    	if (root!=NULL){
    		goPath(root, 0);	
		}
    	
    	return totalSum;
    }
};

int main(){
	return 0;
}
