class Solution(object):
	def maxCoins(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		#	dp[i][j] 将第i到第j个ballons全部burst能得到的最大积分
		n = nums.__len__()
		if (n==0):
			return 0
		if (n==1):
			return nums[0]

		dp = [[0 for j in range(n)] for i in range(n)]
		for i in range(1,n-1):
			dp[i][i] = nums[i] * nums[i-1] * nums[i+1]
		dp[n-1][n-1] = nums[n-1] * nums[n-2]
		dp[0][0] = nums[0] * nums[1]

		for length in range(2,n+1):
			for i in range(0, n - length + 1):
				j = i + length - 1
				dp[i][j] = 0
				for k in range(i,j+1):
					dp[i][j] = max(dp[i][j], (nums[i-1] if i-1>=0 else 1) * (nums[j+1] if j+1<n else 1) * nums[k] + (dp[i][k-1] if k-1>=0 else 0) + (dp[k+1][j] if k+1<n else 0))

		return dp[0][n-1]
