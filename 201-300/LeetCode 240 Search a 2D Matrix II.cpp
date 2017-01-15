class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size()==0 || matrix[0].size()==0 || target<matrix[0][0] || target>matrix[matrix.size()-1][matrix[0].size()-1])
			return false;
		// 每一行做一遍log n的查找
		int left, right, middle;
		for (int i=0;i<matrix.size();i++){
			left = 0;
			right = matrix[i].size()-1;
			while (left<=right){
				middle = (left+right)/2;
				if (matrix[i][middle]==target)
					return true;
				if (matrix[i][middle] < target)
				    left = middle + 1;
				if (matrix[i][middle] > target)
					right = middle - 1;
			}
		}
		return false;
	}
};