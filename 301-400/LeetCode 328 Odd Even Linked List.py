# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def oddEvenList(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		H_Pointer = ListNode(0)
		Even_Pointer = ListNode(0)
		H_Pointer.next = head
		Even = Even_Pointer
		pre_x = H_Pointer
		count = 1
		x = head
		while True:
			if x == None:
				break
			if count % 2 == 0:
				#even
				pass
				#link new listnode
				Even.next = x
				Even = x
				#delete old listnode
				pre_x.next = x.next
				x = pre_x.next
				count += 1
				Even.next = None
			else:
				#odd
				pre_x = x
				x = x.next
				count += 1
				pass
		x = H_Pointer
		while True:
			if x.next == None:
				x.next = Even_Pointer.next
				break
			x = x.next		
		return H_Pointer.next
			
			