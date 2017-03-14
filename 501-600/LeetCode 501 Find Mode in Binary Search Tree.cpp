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
	vector<int> Mode;
	vector<int> PotentialModeCount;
	vector<int> PotentialMode;
	void DiscoverMaxMode(TreeNode* root){
		if (root->left!=NULL)
			DiscoverMaxMode(root->left);
		if (PotentialMode.size() == 0){
			PotentialMode.push_back(root->val);
			PotentialModeCount.push_back(1);
		}
		else{
			if (PotentialMode[PotentialMode.size()-1] == root->val)
				PotentialModeCount[PotentialModeCount.size()-1] += 1;
			else{
				PotentialMode.push_back(root->val);
				PotentialModeCount.push_back(1);		
			}
		}
		if (root->right!=NULL)
			DiscoverMaxMode(root->right);
	}
public:
	vector<int> findMode(TreeNode* root) {
		if (root!=NULL)
			DiscoverMaxMode(root);
		else
			return Mode;

		int MaxModeCount = PotentialModeCount[0];
		for (int i=0;i<PotentialModeCount.size();i++)
			MaxModeCount = max(MaxModeCount, PotentialModeCount[i]);

        cout << MaxModeCount;
		for (int i=0;i<PotentialModeCount.size();i++)
			if (MaxModeCount == PotentialModeCount[i])
				Mode.push_back(PotentialMode[i]);

		return Mode;

	}
};