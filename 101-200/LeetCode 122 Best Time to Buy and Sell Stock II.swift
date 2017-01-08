class Solution {
	func max(_ A: Int, _ B: Int) -> Int {
		if A>B{
			return A
		}
		return B
	} 
	func min(_ A:Int, _ B: Int) -> Int{
		if A<B{
			return A
		}
		else {
			return B
		}
	}
	func maxProfit2(_ prices: [Int]) -> Int {
		var profit: [Int] = []
		var minPrice: Int
		if prices.count <= 1{
			return 0
		}
		for var i in 0..<prices.count{
			profit.append(0)
		}
		// profit[i]: i-th day's max profit
		// profit[i] = max(profit[i] ,profit[j] + prices[i] - min(prices[k] where j<k<i), prices[i] - min(prices[k] where 0<=k<i))
		for var i in 1..<prices.count{
			minPrice = prices[i-1]
			if i>=2{
				for var step in 2...i{
					var j = i - step
					profit[i] = max(profit[i], profit[j] + prices[i] - minPrice)
					minPrice = min(minPrice, prices[j])
				}
			}
			profit[i] = max(profit[i], prices[i] - minPrice)
		}
		var bestProfit = 0
		for var day in 0..<profit.count{
			bestProfit = max(bestProfit, profit[day])
		}
		return bestProfit
	}

	func maxProfit(_ prices: [Int]) -> Int{
		// Greedy Algorithm
		var bestProfit = 0
		if prices.count <= 1{
			return bestProfit
		}
		for var i in 1..<prices.count{
			bestProfit = bestProfit + max(0, prices[i] - prices[i-1])
		}
		return bestProfit
	}
}