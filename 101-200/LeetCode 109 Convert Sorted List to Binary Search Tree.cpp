/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //	最后return的时候会有  Runtime Error
 //	然而跑测试数据的输出没有问题
 // 不解
 // 2017.01.11 
 
#include <iostream>
#include <vector>
#include <queue>


class Solution {
public:
    vector<TreeNode> TreeNodeVectors;
    queue<int> ListQueue;
private:
	void GoTree(TreeNode* root){
		if (root->left!=NULL)
			GoTree(root->left);
		//cout << "here" << endl;
		root->val = ListQueue.front();
		ListQueue.pop();
		//cout << root->val << endl;
		if (root->right!=NULL)
			GoTree(root->right); 
		//cout <<"final";
	}
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head==NULL)
    		return NULL;
    	// get number of ListNode
        int N = 1;
        ListNode* currentListNode;
        currentListNode = head;
        ListQueue.push(head->val);
        while (true){
        	if (currentListNode->next == NULL)
        		break;
        	else{
        		N ++;
        		currentListNode = currentListNode->next;
        		ListQueue.push(currentListNode->val);	
			}
		}
		// build a blank BST;
        TreeNode* TreeHead;
        TreeNode* currentTreeNode;
        for (int i=0;i<N;i++)
        	TreeNodeVectors.push_back(TreeNode(i));
        int leftChild, rightChild;
        for (int i=0;i<N;i++){
        	leftChild = 2*i+1;
        	rightChild = 2*i+2;
        	currentTreeNode = &TreeNodeVectors[i];
        	if (leftChild < N)
        		currentTreeNode->left = &TreeNodeVectors[leftChild];
        	if (rightChild < N)
        		currentTreeNode->right = &TreeNodeVectors[rightChild];
		}
        TreeHead = &TreeNodeVectors[0];
        GoTree(TreeHead);
        //cout << "exit";
        //cout << TreeHead->val;
        return TreeHead;
    }
};
