class Solution(object):
        def guess(self, n):
            if n == 6:
                return 0
            if n > 6:
                return 1
            return -1

	def guessNumber(self, n):
            startKey = 1
            endKey = n
            while True:
                CenterKey = (startKey + endKey) / 2
                print CenterKey
                guessValue = self.guess(CenterKey)
                if guessValue == 0:
                    return CenterKey
                if guessValue > 0:
                    endKey = CenterKey - 1
                else:
                    startKey = CenterKey + 1

print Solution().guessNumber(10)
