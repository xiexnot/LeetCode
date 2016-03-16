# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def removeNthFromEnd(self, head, n):
		"""
		:type head: ListNode
		:type n: int
		:rtype: ListNode
		"""
		if head == None:
			return None
		Link = ListNode(0)
		Link.next = head
		
		LinkLength = 0
		Target = Link
		while True:
			Target = Target.next
			if Target == None:
				break
			LinkLength += 1
			
		Previous = Link
		Target = Link.next
		Count = 1
		while True:
			if Count + n == LinkLength + 1:
				#delete the certain node
				Previous.next = Target.next
				break
			else:
				#next pointer
				Previous = Target
				Target = Target.next
				Count += 1
		
		return Link.next