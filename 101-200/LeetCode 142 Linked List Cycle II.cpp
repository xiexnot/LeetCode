/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// Reference: http://fisherlei.blogspot.tw/2013/11/leetcode-linked-list-cycle-ii-solution.html
		ListNode *slowNode, *fastNode;
		if (head==NULL || head->next == NULL)
			return NULL;
		slowNode = head;
		fastNode = head;
		while (true){
			slowNode = slowNode->next;
			if (slowNode == NULL)
				return NULL;
			fastNode = fastNode->next;
			if (fastNode == NULL)
				return NULL;
			fastNode = fastNode->next;
			if (fastNode == NULL)
				return NULL;
			if (fastNode == slowNode)
				break;
		}
		slowNode = head;
		while (slowNode!=fastNode)
		{
			slowNode = slowNode->next;
			fastNode = fastNode->next;
		}
		return fastNode;
	}
};