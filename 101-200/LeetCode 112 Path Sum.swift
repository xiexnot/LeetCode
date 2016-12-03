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
	func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
		if root == nil{
			return false
		}
		var root = root!
		switch (root.left!, root.right!) {
		case (nil,nil):
			return (sum==root.val) ? true: false
		case (_,nil):
			return hasPathSum(root.right!, sum-root.val)
		case (nil,_):
			return hasPathSum(root.left!, sum-root.val)
		default:
			return hasPathSum(root.right!, sum-root.val) || hasPathSum(root.left!, sum-root.val)
		}
	}
}