class Solution {
	func max(_ A:Int, _ B:Int) -> Int {
		if A>B{
			return A
		}
		else {
			return B
		}
	}
	func min(_ A:Int, _ B:Int) -> Int{
		if A<B{
			return A
		}
		else {
			return B
		}
	}
	func maxProfit(_ prices: [Int]) -> Int {
		var bestProfitGeneralOrder :[Int] = []
		var bestProfitInverseOrder: [Int] = []
		// bestProfitGeneralOrder[i]: best profit in 0-th day...i-th day (the final operation will be not behind  i-th day)
		// bestProfitInverseOrder[i]: best profit in i-th day...n-th day (the first operation will be not early than  i-th day)
		var bestProfit = 0 
		if prices.count <= 1{
			return bestProfit
		}

		for var day in 0..<prices.count{
			bestProfitGeneralOrder.append(0)
			bestProfitInverseOrder.append(0)
		}

		var minPrice = prices[0]
		for var day in 1..<prices.count{
			bestProfitGeneralOrder[day] = max(bestProfitGeneralOrder[day-1], prices[day] - minPrice)
			minPrice = min(minPrice, prices[day])
		}

		var maxPrice = prices[prices.count-1]
		for var day_step in 1..<prices.count{
			var day = prices.count - 1 - day_step
			bestProfitInverseOrder[day] = max(bestProfitInverseOrder[day+1], maxPrice - prices[day])
			maxPrice = max(maxPrice, prices[day])
		} 

		bestProfit = max(bestProfitInverseOrder[0], bestProfitGeneralOrder[prices.count-1])
		for var i in 1..<prices.count{
			bestProfit = max(bestProfit, bestProfitGeneralOrder[i-1] + bestProfitInverseOrder[i])
		}
		return bestProfit
	}
}