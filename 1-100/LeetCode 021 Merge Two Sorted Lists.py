# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def mergeTwoLists(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		Link_A = l1
		Link_B = l2
		Link_All = ListNode(0)
		Target = Link_All
		
		if Link_A == None and Link_B == None:
			return Link_All.next
		if Link_A == None:
			return Link_B
		if Link_B == None:
			return Link_A
		
		while Link_A != None and Link_B != None:
			if Link_A.val < Link_B.val:
				Target.next = ListNode(Link_A.val)
				Link_A = Link_A.next
			else:
				Target.next = ListNode(Link_B.val)
				Link_B = Link_B.next
			Target = Target.next
			
		if Link_A != None:
			while Link_A != None:
				Target.next = ListNode(Link_A.val)
				Link_A = Link_A.next
				Target = Target.next
				
		if Link_B != None:
			while Link_B != None:
				Target.next = ListNode(Link_B.val)
				Link_B = Link_B.next
				Target = Target.next
	
		return Link_All.next