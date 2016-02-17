# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		if l1 == None:
			return l2
		if l2 == None:
			return l1
		Result = ListNode(0)
		p = Result
		addon = 0
		while l1 and l2:
			p.next = ListNode((l1.val + l2.val + addon) % 10)
			if (l1.val + l2.val + addon) >= 10:
				addon = 1
			else:
				addon = 0
			l1 = l1.next
			l2 = l2.next
			p = p.next
		
		if l2:
			while l2:
				p.next = ListNode((l2.val + addon)%10)
				if (l2.val + addon) >= 10:
					addon = 1
				else:
					addon = 0
				l2 = l2.next
				p = p.next
			pass
			
		if l1:
			while l1:
				p.next = ListNode((l1.val+addon) % 10)
				if (l1.val + addon) >= 10:
					addon = 1
				else:
					addon = 0
				l1 = l1.next
				p = p.next
			pass
			
		if addon == 1:
			p.next = ListNode(1)
		return Result.next