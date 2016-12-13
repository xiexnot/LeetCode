/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
	var SortedBST = [Int]()
	func goBST(_ root:TreeNode!) -> Bool{
		if (root == nil){
			return false
		}
		var root_left_node = root.left
		var root_right_node = root.right
		if (root_left_node != nil){
			goBST(root.left)
		}
		SortedBST.append(root.val)
		if (root_right_node != nil){
			goBST(root.right)
		}
		return true
	}
	func isIncreasingArray() -> Bool{
		if SortedBST.count <= 1{
			return true
		}
		for index in 0...(SortedBST.count-1)
		{
			if SortedBST[index]>=SortedBST[index+1]
			{
				return false
			}
		}
		return true
	}
	func isValidBST(_ root: TreeNode?) -> Bool {
		goBST(root)
		return isIncreasingArray()
	}
}	