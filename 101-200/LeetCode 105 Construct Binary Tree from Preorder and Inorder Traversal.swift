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

/*
	I dont know how to extract certain component of Array(e.g. Array[start...goal]) independently...
	So I use two pointer to index the start and goal of Array...
	Too sad...
*/
class Solution {

	func buildTreeNode(_ preorder: [Int], _ preorder_left:Int, _ preorder_right:Int, _ inorder:[Int] , _ inorder_left:Int, _ inorder_right:Int) -> TreeNode{
		var currentTreeNode = TreeNode(preorder[preorder_left])
		var indexOfCenter:Int
		var indexLength:Int
		var indexLength2:Int
		indexOfCenter = inorder.index(of:preorder[preorder_left])!
		indexLength = indexOfCenter - inorder_left 
		indexLength2 = inorder_right - indexOfCenter

		if indexLength > 0 {
			currentTreeNode.left = buildTreeNode(preorder, preorder_left+1, preorder_left + indexLength , inorder, inorder_left, indexOfCenter-1)
		} 
		if indexLength2>0 {
			currentTreeNode.right = buildTreeNode(preorder, preorder_left+1+indexLength , preorder_right,  inorder, inorder_right - indexLength2 + 1,inorder_right)
		} 

		return currentTreeNode
	}

	func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
		if preorder.count == 0 && inorder.count == 0{
			return nil
		}
		if preorder.count == 1 && inorder.count == 1{
			return TreeNode(preorder[0])
		}
		return buildTreeNode(preorder, 0 , preorder.count-1, inorder,0,inorder.count-1)
	}
}