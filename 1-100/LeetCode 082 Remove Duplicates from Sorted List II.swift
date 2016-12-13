/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
	func deleteDuplicates(_ head: ListNode?) -> ListNode? {
		if head == nil{
			return head
		}
		var head = head!
		var headPoint = ListNode(-1)
		headPoint.val = -1
		headPoint.next = head
		var Previous: ListNode?
		Previous = headPoint
		while true {
			var Current = Previous!.next
			if Current == nil{
				break
			}			
			if Current!.next == nil{
				break
			}
			var Current_Next : ListNode?
			Current_Next = Current!.next
			if Current_Next != nil && Current!.val != Current_Next!.val{
				Previous = Current
			}
			else {
				var Next : ListNode?
				Next = Current_Next
				while Next != nil && Next!.val == Current!.val{
					Next = Next!.next
				}
				Previous!.next = Next
			}
		}
		return headPoint.next

	}
}