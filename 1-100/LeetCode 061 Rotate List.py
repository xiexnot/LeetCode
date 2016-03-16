# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def rotateRight(self, head, k):
		"""
		:type head: ListNode
		:type k: int
		:rtype: ListNode
		"""
		if head == None:
			return head
		Counting = 0
		Head_Pointer = ListNode(0)
		Head_Pointer.next = head
		x = head
		e_x = x
		while x!= None:
			Counting += 1
			e_x = x
			x = x.next
		if k / Counting >= 1:
			k = k % Counting
		if k == 0:
			return head
		p_x = Head_Pointer
		x = Head_Pointer
		for i in range(Counting+1-k):
			p_x = x
			x = x.next
		Head_Pointer.next = x
		e_x.next = head
		p_x.next = None
		return Head_Pointer.next
		
		