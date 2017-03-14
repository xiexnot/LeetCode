class Solution {
public:
	int longestPalindromeSubseq(string s) {
		vector< vector<int> > LongestSubsequence;
		int n = s.size();
		if (s.size()<=1)
			return s.size();
		LongestSubsequence.resize(n);
		for (int i=0;i<s.size();i++)
			LongestSubsequence[i].resize(n);

		for (int i=0;i<s.size()-1;i++)
			LongestSubsequence[i][i] = 1;

		for (int i=0;i<s.size()-1;i++)
			if (s[i] == s[i+1])
				LongestSubsequence[i][i+1] = 2;
			else
				LongestSubsequence[i][i+1] = 1;

		int j;
		for (int k=2;k<s.size();k++)
			for (int i=0;i<s.size()-k;i++){
				j = i + k;
				if (s[i] == s[j])
					LongestSubsequence[i][j] = LongestSubsequence[i+1][j-1] + 2;
				else
					LongestSubsequence[i][j] = max(LongestSubsequence[i+1][j], LongestSubsequence[i][j-1]);
			}
		return LongestSubsequence[0][s.size()-1];

	}
};