class Solution {
private:
	int calculate_one_char(char x){
		int current;
		current = x - '0';
		if (current>0 && current<=9)
			return 1;
		else
			return 0;
	}
	int calculate_two_char(char x1, char x2){
		int current;
		current = (x1-'0')*10 + (x2-'0');
		//	判断是合法的two bits 方案
		//	这里应该是>=10而非current>=0 不然对于01 02等伪二位的decode digit会被判断为true
		if (current>=10 && current<=26)
			return 1;
		else
			return 0;
	}
public:
    int numDecodings(string s) {
    	if (s.size()==0)
    		return 0;
  		vector<int> ways(s.size(),0);
  		int last_char;
  		for (int i=0;i<s.size();i++){
  			
  			if (i!=0 && calculate_one_char(s[i]))
  				// i != 0
  				ways[i] = ways[i] + ways[i-1];
  			if (i==0 && calculate_one_char(s[i]))
  				// i == 0
  				ways[i] = ways[i] + 1;
  			
  			if (i>=2 && calculate_two_char(s[i-1],s[i]))
  				ways[i] = ways[i] + ways[i-2];
  			if (i==1 && calculate_two_char(s[i-1],s[i]))
  				ways[i] = ways[i] + 1;
  		}
  		return ways[s.size()-1];
    }
};