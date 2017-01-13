class Solution {
private:
	int xDirection[4] = {1,-1,0,0};
	int nSize, mSize;
	int yDirection[4] = {0,0,+1,-1};
	void fill(vector<vector<char>>& grid, int xStart, int yStart) {
		int xCurrent, yCurrent, xNext, yNext;
		queue<int> xQueue;
		queue<int> yQueue;
		xQueue.push(xStart);
		yQueue.push(yStart);
		grid[xStart][yStart] = '0';
		while (!xQueue.empty()){
			xCurrent = xQueue.front();
			xQueue.pop();
			yCurrent = yQueue.front();
			yQueue.pop();
			for (int q=0;q<4;q++){
				xNext = xCurrent + xDirection[q];
				yNext = yCurrent + yDirection[q];
				if (xNext<0 || xNext>=nSize || yNext<0 || yNext>=mSize)
					continue;
				if (grid[xNext][yNext] == '0')
					continue;
				grid[xNext][yNext] = '0';
				xQueue.push(xNext);
				yQueue.push(yNext);
			}
		}
	}
public:
    int numIslands(vector<vector<char>>& grid) {
    	nSize = grid.size();
    	if (nSize==0)
    		return 0;
    	mSize = grid[0].size();
    	if (mSize==0)
    		return 0;
    	int islandCount;
    	for (int i=0;i<nSize;i++)
    		for (int j=0;j<mSize;j++)
    			if (grid[i][j] == '1'){
    				fill(grid,i,j);
    				islandCount ++;
    			}
    	return islandCount;
    }
};