class Solution {
private:
	int min(int a, int b){
		return (a<b)? a:b;
	}
	int max(int a, int b){
		return (a>b)? a:b;
	}
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		// grid[i][j] 从[i][j]出发 向左上角扩散 得到的最大matrix边长
		// row[i][j] 从[i][j]出发 向左可以构成matrix边的最大长度
		// column[i][j] 从[i][j]出发 向上可以构成matrix边的最大长度
		if (!matrix.size())
			return 0;
		std::vector<std::vector<int>> grid(matrix.size(),std::vector<int> (matrix[0].size(),0));
		std::vector<std::vector<int>> row(matrix.size(),std::vector<int> (matrix[0].size(),0));
		std::vector<std::vector<int>> column(matrix.size(),std::vector<int> (matrix[0].size(),0));

		for(int i=0;i<matrix.size();i++){
			row[i][0] = ((matrix[i][0] == '1')? 1:0);
			for (int j=1;j<matrix[i].size();j++)
				row[i][j] = (matrix[i][j]=='1'? row[i][j-1]+1:0);
		}

		for (int j=0;j<matrix[0].size();j++){
			column[0][j] = (matrix[0][j] == '1'?1:0);
			for (int i=1; i<matrix.size();i++)
				column[i][j] = (matrix[i][j] == '1'? column[i-1][j]+1:0);
		}

		int target_i, target_j;
		for (int i=0;i<matrix.size();i++)
			for (int j=0;j<matrix[i].size();j++){
				if (i && j){
					// i > 0 && j > 0
					grid[i][j] = min(row[i][j], column[i][j]);
					grid[i][j] = min(grid[i][j], grid[i-1][j-1]+1);
				}
				else{
					// i==0 or j==0
					grid[i][j] = min(row[i][j], column[i][j]);
				}
			}

		int result = 0;
		for (int i=0;i<matrix.size();i++)
			for (int j=0;j<matrix[i].size();j++)
				result = max(result, grid[i][j]);
		return result*result;
	}
};