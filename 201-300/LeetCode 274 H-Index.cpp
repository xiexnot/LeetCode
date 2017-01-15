class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(),citations.end());
		int h = citations[citations.size()-1];
		for (int i=citations.size()-1;i>=0;i--){
			h = citations[i];
			if (citations.size()-i >= h) 
				return h;
		}
		return 0;
	}
};