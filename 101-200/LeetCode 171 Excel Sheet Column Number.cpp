class Solution {
public:
    int titleToNumber(string s) {
        int count = 0;
        int charint;
        int base = 1;
        for (int i=s.size()-1;i>=0;i--){
        	charint = ( s[i] + 1 - 'A');
        	cout << charint;
        	count = count + base * charint ;
        	base = base * 26;
        }
        return count;
    }
};