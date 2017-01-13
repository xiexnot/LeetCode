class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		// Reference: 如何使用pair类型 http://www.cplusplus.com/reference/utility/pair/

		// 判断是否为拓扑图
		std::vector<int> incoming(numCourses,0);
		// 将prerequisites构建为边表
		std::vector<int> head(numCourses,-1);
		std::vector<int> prev(prerequisites.size(),-1);
		std::vector<int> ending(prerequisites.size(),-1);
		int pair_from, pair_to;
		for (int i=0;i<prerequisites.size();i++){
			pair_to = prerequisites[i].first;
			pair_from = prerequisites[i].second;
			ending[i] = pair_to;
			prev[i] = head[pair_from];
			head[pair_from] = i;
			incoming[pair_to] ++;
		}

		// 维护搜索队列 队列中为当前incoming度为0的节点
		queue<int> emptyIncoming;
		for (int i=0;i<numCourses;i++)
			if (incoming[i]==0)
				emptyIncoming.push(i);
		int finishCourse = 0;
		int currentCourse, nextCourse, nextEdge;
		while (!emptyIncoming.empty()){
			currentCourse = emptyIncoming.front();
			emptyIncoming.pop();
			finishCourse ++;
			nextEdge = head[currentCourse];
			while (nextEdge>=0){
				nextCourse = ending[nextEdge];
				incoming[nextCourse] -- ;
				if (incoming[nextCourse] == 0)
					emptyIncoming.push(nextCourse);
				nextEdge = prev[nextEdge];
			}
		}
		if (finishCourse != numCourses)
			return false;
		else
			return true;
	}
};