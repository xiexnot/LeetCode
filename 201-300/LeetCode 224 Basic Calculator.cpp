class Solution {
private:
	int operate(long a, long b, long op){
		if (op=='+')
			return a+b;
		if (op=='-')
			return a-b;
		if (op=='*')
			return a*b;
		return 0;
	}
public:
	int calculate(string s) {
		stack<char> op;
		stack<long> op_level;
		stack<long> num;

		long op_base;
		long current_level;
		long current = 0;
		long num1, num2;

		for (int i=0;i<s.size();i++){
			if (s[i] == ' ')
				continue;
			if (s[i] == '(')
				op_base = op_base + 4;
			if (s[i] == ')')
				op_base = op_base - 4;
			if (s[i] == '+' || s[i] == '-' || s[i] == '*'){
				num.push(current);
				current = 0;
				current_level = (s[i]=='*'?2:1) + op_base;
				while (op_level.empty()==false && op_level.top() >= current_level){
					num1 = num.top();
					num.pop();
					num2 = num.top();
					num.pop();
					num.push(operate(num2, num1, op.top()));
					op.pop();
					op_level.pop();
				}
				op.push(s[i]);
				op_level.push(current_level);
			}
			if (s[i] >= '0' && s[i] <= '9'){
				current = current * 10 + s[i] - '0';
			}
		}
		
        num.push(current);
		while (op_level.empty()==false){
			num1 = num.top();
			num.pop();
			num2 = num.top();
			num.pop();
			num.push(operate(num2, num1, op.top()));
			op.pop();
			op_level.pop();
		}

		return num.top();
		
	}
};