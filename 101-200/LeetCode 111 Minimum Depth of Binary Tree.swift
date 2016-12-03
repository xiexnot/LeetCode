//
//	发现 依照当前的写法
//	如果传入的x是null的时候 程序总是会有出错
//	所以都得在调用之前 来判断说是不是null
//	参看： 隐式解析可选类型
//

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
	func min(_ a: Int,_ b: Int) -> Int{
		var result = a<b ? a : b
		return result
	}
	func DepthCalculate(_ x: TreeNode) -> Int{
		if x.left == nil && x.right == nil{
			return 1
		}
		if (x.left) == nil{
			return DepthCalculate(x.right!) + 1
		}
		if (x.right) == nil{
			return DepthCalculate(x.left!) + 1
		}
		let minLeftDepth = DepthCalculate(x.left!)
		let minRightDepth = DepthCalculate(x.right!)
		return min(minLeftDepth, minRightDepth) + 1
	}
	
	func minDepth(_ root: TreeNode?) -> Int {
		if root != nil{
			return DepthCalculate(root!)
		}
		return 0
	}
}