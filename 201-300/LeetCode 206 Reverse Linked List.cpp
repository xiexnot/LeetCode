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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode * prev, * current, * next;
		prev = head;
		current = prev->next;
		head->next = NULL;
		// 三指针索引
		// 强行reverse
		while (true){
			next = current->next;
			current->next = prev;
			if (next == NULL)
				return current;
			prev = current;
			current = prev->next;
		}
	}
};