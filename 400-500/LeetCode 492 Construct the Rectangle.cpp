class Solution {
public:
	vector<int> constructRectangle(int area) {
		int L;
		vector<int> Rectangle;
		L = (int) sqrt(area);
		for (int i=L;i>0;i--)
			if (area%i == 0){
				Rectangle.push_back(area/i);
				Rectangle.push_back(i);
				return Rectangle;
			}
	}
};