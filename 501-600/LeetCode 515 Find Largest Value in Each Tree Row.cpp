/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<vector>
#include<cstring>
#include<string>

using namespace std;

class Solution {
private:
	vector<int> largestValue;
private:
	int min(int a, int b){
		return (a>b?a:b);
	}
private:
	void DiscoverRoot(TreeNode* x, int depth){
		if (largestValue.size() < depth){
			largestValue.push_back(x->val);
		}
		else
		{
			largestValue[depth-1] = max(largestValue[depth-1], x->val);
		}
		if (x->left != NULL)
			DiscoverRoot(x->left, depth+1);
		if (x->right != NULL)
			DiscoverRoot(x->right, depth+1);
	}
public:
	vector<int> largestValues(TreeNode* root) {
		if (root==NULL)
			return largestValue;
		DiscoverRoot(root,1);
		return largestValue;
	}
};