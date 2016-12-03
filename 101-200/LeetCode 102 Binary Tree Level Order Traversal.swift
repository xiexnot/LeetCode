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
	var LevelOrderArray = [[Int]]()
	var LevelOrderDepth = -1
	func DepthSearch(_ x: TreeNode, Depth: Int) -> Bool{
		if x == nil {
			return false
		}
		if Depth > LevelOrderDepth{
			LevelOrderDepth = Depth
			LevelOrderArray.append([])
		}
		LevelOrderArray[Depth].append(Int(x.val))
		if x.left != nil{
			DepthSearch(x.left!, Depth: Depth+1)
		}
		if x.right != nil{
			DepthSearch(x.right!, Depth: Depth+1)
		}
		return true
	}
	func levelOrder(_ root: TreeNode?) -> [[Int]] {
		if root != nil{
			DepthSearch(root!,Depth: 0)
		}
		return LevelOrderArray
	}
}