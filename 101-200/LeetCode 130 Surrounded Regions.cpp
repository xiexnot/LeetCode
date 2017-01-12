//	写着写着就Runtime Error（用DFS）
//	写着写着就TLE（用BFS)
/*

[
"XOOOOOOOOOOOOOOOOOOO",
"OXOOOOXOOOOOOOOOOOXX",
"OOOOOOOOXOOOOOOOOOOX",
"OOXOOOOOOOOOOOOOOOXO",
"OOOOOXOOOOXOOOOOXOOX",
"XOOOXOOOOOXOXOXOXOXO",
"OOOOXOOXOOOOOXOOXOOO",
"XOOOXXXOXOOOOXXOXOOO",
"OOOOOXXXXOOOOXOOXOOO",
"XOOOOXOOOOOOXXOOXOOX",
"OOOOOOOOOOXOOXOOOXOX",
"OOOOXOXOOXXOOOOOXOOO",
"XXOOOOOXOOOOOOOOOOOO",
"OXOXOOOXOXOOOXOXOXOO",
"OOXOOOOOOOXOOOOOXOXO",
"XXOOOOOOOOXOXXOOOXOO",
"OOXOOOOOOOXOOXOXOXOO",
"OOOXOOOOOXXXOOXOOOXO",
"OOOOOOOOOOOOOOOOOOOO",
"XOOOOXOOOXXOOXOXOXOO"
]


*/

class Solution {
private:
	int nSize, mSize;
	vector<int> xDirection = {1,-1,0,0};
	vector<int> yDirection = {0,0,-1,1};
	queue<int> xQueue;
	queue<int> yQueue;
private:
	void floodfill(vector<vector<char>>& board, int x, int y){
		/*
		if (x<0 || x>=nSize || y<0 || y>=mSize )
			return ;
		if (board[x][y]!='O')
			return ;
		board[x][y] = '-';
		floodfill(board,x-1,y);
		floodfill(board,x+1,y);
		floodfill(board,x,y+1);
		floodfill(board,x,y-1);
		*/
		int xNext, yNext;
		int xCurrent, yCurrent;
		xQueue.push(x);
		yQueue.push(y);
		while (!xQueue.empty()){
			xCurrent = xQueue.front();
			yCurrent = yQueue.front();
			xQueue.pop();
			yQueue.pop();
			board[xCurrent][yCurrent] = '-';
			for (int q=0;q<4;q++){
				xNext = xCurrent + xDirection[q];
				yNext = yCurrent + yDirection[q];
				if (xNext<0 || xNext>=nSize || yNext<0 || yNext>=mSize )
					continue ;
				if (board[xNext][yNext]!='O')
					continue ;
				xQueue.push(xNext);
				yQueue.push(yNext);
			}
		}
	}
public:
    void solve(vector<vector<char>>& board) {
        //	最外层做floodfill
        //	如果原来是O的被覆盖到 则最后输出的时候保留O
        //	如果原来是O的没有被覆盖到 则最后输出的时候改成X

    	//	floodfill
    	//	覆盖到的区域为 - 
    	nSize = board.size();
    	if (nSize == 0) {
    		return;
    	}
    	mSize = board[0].size();
    	for (int i=0;i<nSize;i++) {
    		if (board[i][0] == 'O')
    			floodfill(board,i,0);
    		if (board[i][mSize-1] == 'O')
    			floodfill(board,i,mSize-1);
    	}
    	for (int j=0;j<mSize;j++) {
    		if (board[0][j] == 'O')
    			floodfill(board,0,j);
    		if (board[nSize-1][j] == 'O')
    			floodfill(board,nSize-1,j);
    	}

    	//	重置board
    	//	如果board[i][j]为O 则改为X
    	//	如果board[i][j]为- 则改为O
    	for (int i=0;i<nSize;i++)
    		for (int j=0;j<mSize;j++) {
    			if (board[i][j] == 'O')
    				board[i][j] = 'X';
    			if (board[i][j] == '-')
    				board[i][j] = 'O';
    		}		
    }
};