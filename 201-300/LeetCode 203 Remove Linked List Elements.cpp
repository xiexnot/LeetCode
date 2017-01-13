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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * trueHead, * current;
        trueHead = new ListNode(-100000000);
        trueHead->next = head;
        current = trueHead;
        while (true){
        	if (current->next == NULL)
        		break;
        	if (current->next->val == val)
        		current->next = current->next->next;
        	else
        		current = current->next;
        }
        return trueHead->next;
    }
};