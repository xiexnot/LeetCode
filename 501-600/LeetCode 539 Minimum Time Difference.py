class Solution(object):
    def convert(self, x):
        xList = x.split(":")
        xList[0] = int(xList[0])
        xList[1] = int(xList[1])
        return xList[0] * 60 + xList[1]
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        timestampPoints = []
        for timeItem in timePoints:
            timestampPoints.append(self.convert(timeItem))
        timestampPoints.sort()

        minDifference = self.convert("24:00") + timestampPoints[0] - timestampPoints[timestampPoints.__len__()-1]
        for i in range(1,timestampPoints.__len__()):
            minDifference = min(minDifference, timestampPoints[i] - timestampPoints[i-1])
        
        return minDifference

        
