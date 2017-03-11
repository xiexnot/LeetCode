class Solution(object):
	def maxProfit(self, prices):
		"""
		:type prices: List[int]
		:rtype: int
		"""
		"""
		sell[i] 表示第i天未持股时，获得的最大利润，buy[i]表示第i天持有股票时，获得的最大利润。
		对于sell[i]，最大利润有两种可能，一是今天没动作跟昨天未持股状态一样，二是今天卖了股票
		sell[i] = max{sell[i - 1], buy[i-1] + prices[i-1]}
		对于buy[i]，最大利润有两种可能，一是今天没动作跟昨天持股状态一样，二是前天卖了股票，今天买了股票，因为 cooldown 只能隔天交易，所以今天买股票要追溯到前天的状态。
		"""
		if (prices.__len__()==0):
			return 0;
		sell = [0 for i in range(prices.__len__())]
		buy = [0 for i in range(prices.__len__())]
		sell[0] = 0
		buy[0] = (-1)*prices[0]
		for i in range(1, prices.__len__()):
			sell[i] = max(sell[i-1], buy[i-1] + prices[i])
			if (i-2>=0):
				buy[i] = max(buy[i-1], sell[i-2] - prices[i])
			else:
				buy[i] = max(buy[i-1], (-1)*prices[i])
		return sell[prices.__len__()-1]