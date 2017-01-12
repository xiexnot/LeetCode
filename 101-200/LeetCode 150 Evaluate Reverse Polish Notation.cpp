#include <vector>
#include <iostream>
#include <stack>

using namespace std; 

class Solution {
private:
	stack<int> RPNstack;
private:
	int operation(int x, int y, string op){
		if (op=="+")
			return x+y;
		if (op=="-")
			return x-y;
		if (op=="*")
			return x*y;
		if (op=="/")
			return x/y;
		return 0;
	}
public:
	int evalRPN(vector<string>& tokens) {
		int x,y;
		for (int i=0;i<tokens.size();i++)
			//cout << tokens[i] << endl;
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
				x = RPNstack.top();
				RPNstack.pop();
				y = RPNstack.top();
				RPNstack.pop();
				RPNstack.push(operation(y,x,tokens[i]));
			}
			else{
				RPNstack.push(stoi(tokens[i]));
			}
		return to_string(RPNstack.top());

	}
};

int main(){
	vector<string> tokens;
	tokens.push_back("18");
	cout << Solution().evalRPN(tokens) << endl;
}
