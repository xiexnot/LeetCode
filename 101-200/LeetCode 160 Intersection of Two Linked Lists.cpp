/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include <iostream>

using namespace std;

class Solution {
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//  link(a): m_1 -> m_2 -> ...-> m_a -> c1 -> c2 ->... -> c_x
		//  link(b): n_1 -> n_2 -> ...-> n_b -> c1 -> c2 ->... -> c_x
		// a+x = length(a)
		// b+x = length(b)
		// length(a)-length(b) = a - b
		// 看长link先走了a-b步 而后长短link同时开始走能否intersect 
		int ALength, BLength;
		ListNode* currentNode;
		ALength = 0;
		BLength = 0;
		currentNode = headA;
		while (currentNode!=NULL){
			ALength ++;
			currentNode = currentNode->next;
		}
		currentNode = headB;
		while (currentNode!=NULL) {
			BLength ++;
			currentNode = currentNode->next;
		}
		int minusLength;
		minusLength = ALength - BLength;
		ListNode* shortLinkNode;
		ListNode* longLinkeNode;
		if (minusLength >= 0){
			longLinkeNode = headA;
			shortLinkNode = headB;
		}
		else {
			longLinkeNode = headB;
			shortLinkNode = headA;
			minusLength = (-1)*minusLength;
		}
		for(int i=0;i<minusLength;i++)
			longLinkeNode = longLinkeNode->next;
		while (longLinkeNode!=NULL && shortLinkNode!=NULL){
			if (longLinkeNode == shortLinkNode)
				return shortLinkNode;
			longLinkeNode = longLinkeNode->next;
			shortLinkNode = shortLinkNode->next;
		}
		return NULL;
	}
};
int main(){
	return 0;
}
