class Solution {
	func generate(_ numRows: Int) -> [[Int]] {
		var pascalTriangle = [[Int]]()
		pascalTriangle.append([1])
		pascalTriangle.append([1,1])
		var pascalTriangleItem = [Int]()
		switch numRows {
		case 0:
			return []
		case 1:
			return [[1]]
		case 2:
			return [[1],[1,1]]
		default:
			
			for var step in 3...numRows{
				pascalTriangleItem = []
				pascalTriangleItem.append(1)
				for var i in 1...step-2{
					pascalTriangleItem.append(pascalTriangle[step-2][i]+pascalTriangle[step-2][i-1])
				}
				pascalTriangleItem.append(1)
				pascalTriangle.append(pascalTriangleItem)
			}
			return pascalTriangle
		}
	}
}