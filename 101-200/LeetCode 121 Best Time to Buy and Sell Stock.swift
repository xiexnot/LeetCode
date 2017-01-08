class Solution {
	func max(_ A:Int, _ B:Int) -> Int{
		if A>B {
			return A
		}
		return B
	}
	func min(_ A:Int, _ B:Int) -> Int{
		if A>B {
			return B
		}
		return A
	}
	func maxProfit(_ prices: [Int]) -> Int {
		var bestProfit = 0
		if prices.count == 0{
			return bestProfit
		}
		var minStock = prices[0]
		for var i in 1..<prices.count {
			bestProfit = max(bestProfit, prices[i] - minStock)
			minStock = min(minStock, prices[i])
		}
		return bestProfit
	}
}