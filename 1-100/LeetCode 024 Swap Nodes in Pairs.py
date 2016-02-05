# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def swapPairs(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		head_Pointer = ListNode(0)
		head_Pointer.next = head
		P = head_Pointer
		try:
			Q = head
			R = head.next
		except:
			return head_Pointer.next
		while True:
			if Q == None or R == None:
				break
			P.next = R
			Q.next = R.next
			R.next = Q
			P = R.next
			try:
				Q = P.next
				R = Q.next
			except:
				break
		return head_Pointer.next
