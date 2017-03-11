import Queue

class Solution(object):

	def CreateGraph(self, n, edges):
		prev = [-1 for i in range(edges.__len__()*2)]
		ending = [-1 for i in range(edges.__len__()*2)]
		head = [-1 for i in range(n)]
		InOut = [0 for i in range(n)]
		count = 0;
		for i in range(edges.__len__()):

			prev[count] = head[edges[i][0]]
			head[edges[i][0]] = count
			ending[count] = edges[i][1]
			count += 1

			prev[count] = head[edges[i][1]]
			head[edges[i][1]] = count
			ending[count] = edges[i][0]
			count += 1

			InOut[edges[i][0]] += 1
			InOut[edges[i][1]] += 1
		return prev, ending, head, InOut


	def findMinHeightTrees(self, n, edges):
		"""
		:type n: int
		:type edges: List[List[int]]
		:rtype: List[int]
		"""
		if (n<=2):
			return [i for i in range(n)]
		prev, ending, head, InOut = Solution().CreateGraph(n, edges)

		#	使用剥洋葱法
		#	把叶子节点不断拨开 最后只会剩下一个节点或者是两个节点
		#	此时剩余节点即为所求解
		queue = Queue.Queue()
		level_queue = Queue.Queue()
		isVisited = [False for i in range(n)]
		VisitOrder = []
		VisitLevel = []
		remainNodeCount = n

		for i in range(n):
			if InOut[i] == 1:
				queue.put(i)
				level_queue.put(1)
				isVisited[i] = True
				VisitOrder.append(i)
				VisitLevel.append(1)
				remainNodeCount -= 1

		while (remainNodeCount > 0 or queue.empty()==False):
			#	剥洋葱到最后
			currentNode = queue.get()
			currentNodeLevel = level_queue.get()
			currentEdge = head[currentNode]
			
			while (currentEdge>=0):
				if isVisited[ending[currentEdge]] is False:
					InOut[ending[currentEdge]] -= 1
					if (InOut[ending[currentEdge]] == 1):
						queue.put(ending[currentEdge])
						level_queue.put(currentNodeLevel+1)
						VisitOrder.append(ending[currentEdge])
						VisitLevel.append(currentNodeLevel+1)
						isVisited[ending[currentEdge]] = True
						remainNodeCount -= 1
				currentEdge = prev[currentEdge]

		maxNodeLevel = max(VisitLevel)
		resultTreeNode = []
		for i in range(n):
			if VisitLevel[i] == maxNodeLevel:
				resultTreeNode.append(VisitOrder[i])

		return resultTreeNode

