class Solution {
	func swap(_ a: inout Int, _ b: inout Int){
		var tmp = a
		a = b
		b = tmp
	}
	func getRow(_ rowIndex: Int) -> [Int] {
		var pascalTriangleRow = [[Int]]()
		var previous, current: Int
		switch rowIndex {
		case 0:
		    return [1]
		case 1:
			return [1,1]
		default:
			var pascalTriangleItem = [Int]()
			for i in 0...rowIndex{
				pascalTriangleItem.append(0)
			}
			pascalTriangleRow.append(pascalTriangleItem)
			pascalTriangleRow.append(pascalTriangleItem)
			previous = 0
			current = 1
			pascalTriangleRow[previous][0] = 1
			pascalTriangleRow[previous][1] = 1
			for var step in 2...rowIndex{
				pascalTriangleRow[current][0] = 1
				for var i in 1...rowIndex{
					pascalTriangleRow[current][i] = pascalTriangleRow[previous][i] + pascalTriangleRow[previous][i-1]
				}
				
				swap(&previous, &current)
			}
			return pascalTriangleRow[previous]

		}
	}
}