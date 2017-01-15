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
    void deleteNode(ListNode* node) {
        // 在某个ListNode中删除特定的node 然后返回下一个node
        // 因为输入的只有当前待删除的node
        // 所以这里的做法是把下一个node的资料复制到当前node中 然后删除下一个node
        node->val = node->next->val;
        node->next = node->next->next;
    }
};