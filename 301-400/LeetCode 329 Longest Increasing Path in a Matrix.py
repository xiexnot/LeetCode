class Solution(object):
	def longestIncreasingPath(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: int
		"""
		S = []
		for i in range(matrix.__len__()):
			for j in range(len(matrix[i])):
				S.append([matrix[i][j],i,j])
		S = sorted(S)
		
		if S == []:
			return 0
		D = []
		len1 = matrix.__len__()
		len2 = len(matrix[0])
		for i in range(len1):
			tmp = []
			for j in range(len2):
				tmp.append(1)
			D.append(tmp)
		
		Step = [[-1,0],[+1,0],[0,-1],[0,+1]]
		for i in range(S.__len__()):
			x = S[i][1]
			y = S[i][2]
			for q in range(Step.__len__()):
				if x + Step[q][0] >= 0 and x + Step[q][0] < len1 and y + Step[q][1] >= 0 and y + Step[q][1] < len2:
					if matrix[x + Step[q][0]][y + Step[q][1]] > matrix[x][y] and  D[x + Step[q][0]][y + Step[q][1]] < D[x][y] + 1:
						D[x + Step[q][0]][y + Step[q][1]] = D[x][y] + 1
			#print "i = ",i," D = ", D
		
		Result = 1
		for i in range(len1):
			for j in range(len2):
				if D[i][j] > Result:
					Result = D[i][j]
		#print D
		#print S
		return Result
			
				
				