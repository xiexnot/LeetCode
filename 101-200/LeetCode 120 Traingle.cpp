class Solution {
private:
	int max(int a,int b){
		return (a>b)? a:b;
	}
private:
    int min(int a, int b) {
        return (a<b)? a:b;
    }
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int nSize, mSize;
		if (triangle.size() == 1)
			return triangle[0][0];
		nSize = triangle.size();
		mSize = triangle[nSize-1].size();
		vector<vector<int>>  row(2,vector<int>(mSize,10000000));
		row[0][0] = triangle[0][0];
		int index1, index2, tmp;
		index1 = 0;
		index2 = 1;
		for (int i=1;i<nSize;i++){
			for (int j=0;j<=i;j++){
				row[index2][j] = min(10000000, row[index1][j] + triangle[i][j]);
				if (j-1>=0)
					row[index2][j] = min(row[index2][j], row[index1][j-1] + triangle[i][j]);
			}
			tmp = index1;
			index1 = index2;
			index2 = tmp;
		}
		int result= 10000000;
		for (int j=0;j<mSize;j++)
			result = min(result, row[index1][j]);
		return result;
	}
};