/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	vector<int> values;
private:
	bool isExist(int value) {
		if (values.empty())
			return false;
		for (int i=0;i<values.size();i++)
			if (values[i] == value)
				return true;
		return false;
	}
public:
	bool hasCycle(ListNode *head) {
		// 双指针，快指针走两步，慢指针走一步
		// 如果重叠则为cycle
		ListNode *slowNode,*fastNode;
		if (head==NULL || head->next==NULL)
			return false;
		slowNode = head;
		fastNode = head;
		while (true){
			slowNode = slowNode->next;
			if (slowNode == NULL)
				return false;
			fastNode = fastNode->next;
			if (fastNode == NULL)
				return false;
			fastNode = fastNode->next;
			if (fastNode == NULL)
				return false;
			if (fastNode == slowNode)
				return true;
		}
	}
};