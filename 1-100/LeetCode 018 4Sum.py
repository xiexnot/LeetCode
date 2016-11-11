class Solution(object):
	def fourSum(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[List[int]]
		"""
		result = []
		nums.sort()
		length = nums.__len__()
		for first in range(length-3):
			if first > 0 and nums[first] == nums[first-1]:
				continue
			for second in range(first+1,length-2):
				if second > first + 1 and nums[second] == nums[second-1]:
					continue
				third = second + 1
				forth = length - 1
				while third < forth:
					if nums[first] + nums[second] + nums[third] + nums[forth] == target:
						pass
						result.append([nums[first],nums[second],nums[third],nums[forth]])
						while third < forth:
							third += 1
							if nums[third] != nums[third-1]:
								break
						while third < forth:
							forth -= 1
							if nums[forth] != nums[forth+1]:
								break

					elif nums[first] + nums[second] + nums[third] + nums[forth] < target:
						pass
						while third < forth:
							third += 1
							if nums[third] != nums[third-1]:
								break
					else:
						while third < forth:
							forth -= 1
							if nums[forth] != nums[forth+1]:
								break
						pass

		return result

if __name__ == "__main__":
	print Solution().fourSum([-500,-499,-496,-467,-467,-465,-461,-460,-456,-456,-447,-426,-425,-401,-377,-367,-344,-338,-332,-329,-328,-294,-281,-262,-256,-224,-196,-192,-171,-161,-151,-138,-130,-109,-109,-107,-104,-101,-97,-96,-90,-78,-76,-70,-28,-23,-4,30,39,46,60,80,97,120,172,183,194,197,206,238,242,243,252,303,338,341,349,362,366,367,372,393,400,403,406,411,416,454,457,460,497],-1963)

