#include<stack>

class MinStack {
private:
	stack<int> min_stack;
	stack<int> elements_stack;
public:
	MinStack() {
		
	}
	
	void push(int x) {
		elements_stack.push(x);
		if (min_stack.empty() || min_stack.top() >= x)
			min_stack.push(x);
	}
	
	void pop() {
		if (elements_stack.empty())
			return ;
		if (elements_stack.top() == min_stack.top())
			min_stack.pop();
		elements_stack.pop();
	}
	
	int top() {
		return elements_stack.top();
	}
	
	int getMin() {
		return min_stack.top();
	}
};
 