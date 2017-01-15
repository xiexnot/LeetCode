class Solution {
public:
	string getHint(string secret, string guess) {
		// 一遍扫描的bull and cow问题
		int m[256] = {0}, bulls = 0, cows = 0;
		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) ++bulls;
			else ++m[secret[i]];
		}
		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] != guess[i] && m[guess[i]]) {
				++cows;
				--m[guess[i]];
			}
		}
		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};