class Solution {
private:
	int n,m;
	bool isValid(int x, int y){
		if (x<0 || y<0 || x>=n || y>=m)
			return false;
		return true;
	}
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> DiagonalOrder;
		int currentx, currenty, currentDirection;
		int nextx, nexty;
		if (!matrix.size())
			return DiagonalOrder;

		currentx = 0;
		currenty = 0;
		currentDirection = 1;
		int total = matrix.size() * matrix[0].size();
		n = matrix.size();
		m = matrix[0].size();
		while (total){
			//cout << currentx << " " << currenty << " " << currentDirection <<endl;
			DiagonalOrder.push_back(matrix[currentx][currenty]);
			if (currentDirection == 1){
				nextx = currentx - 1;
				nexty = currenty + 1;
				if (!isValid(nextx, nexty)){
					currentDirection = -1;
					//cout <<"change direction" << endl;
					if (isValid(currentx, currenty+1)){
						nextx = currentx;
						nexty = currenty+1;
					}
					else{
						nextx = currentx+1;
						nexty = currenty;
					}
				}
			}
			else{
				nextx = currentx + 1;
				nexty = currenty - 1;
				if (!isValid(nextx, nexty)){
					currentDirection = 1;
					if (isValid(currentx+1, currenty)){
						nextx = currentx + 1;
						nexty = currenty;
					}
					else{
						nextx = currentx;
						nexty = currenty+1;
					}

				}
			}
			currentx = nextx;
			currenty = nexty;
			total --;
		}
		return DiagonalOrder;
	}
};