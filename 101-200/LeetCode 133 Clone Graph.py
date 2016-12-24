class Solution(object):
	def cloneGraph(self, node):
		"""
		:type node: UndirectedGraphNode
		:rtype: UndirectedGraphNode
		"""
		if not node:
			return None

		return self.dfs(node, {})

	def dfs(self, node, map):
		if node in map:
			return map[node]
		newNode = UndirectedGraphNode(node.label)
		map[node] = newNode
		for neighbor in node.neighbors:
			newNode.neighbors.append(self.dfs(neighbor, map))

		return newNode