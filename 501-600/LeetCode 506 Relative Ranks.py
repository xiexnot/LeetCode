class Solution(object):
	def findRelativeRanks(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[str]
		"""
		RankRecord = []
		for index in range(nums.__len__()):
			RankRecord.append((nums[index], index))
		RankRecord.sort(reverse= True)
		ranks = []
		for index in range(RankRecord.__len__()):
			ranks.append("")
		for index in range(RankRecord.__len__()):
			ranks[RankRecord[index][-1]] = str(index+1)
		for index in range(ranks.__len__()):
			if ranks[index] == "1":
				ranks[index] = "Gold Medal"
			if ranks[index] == "2":
				ranks[index] = "Silver Medal"
			if ranks[index] == "3":
				ranks[index] = "Bronze Medal"
		return ranks
