
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
struct cmp1
{
	bool operator()(long a, long b){
		return (a < b? true : false);
	}
};
struct cmp2
{
	bool operator()(long a, long b){
		return (a > b? true : false);
	}
};
// 使用左右堆，左为最大堆，右为最小堆。
// 维护两个堆大小相同或左栈大于右栈一个元素
private:
	priority_queue<long, vector<long>, cmp1> left_priority_queue;
	priority_queue<long, vector<long>, cmp2> right_priority_queue;
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		if (left_priority_queue.size() == right_priority_queue.size()){
			// 左右堆大小相同
			// 如果新的数字加入左边 则直接加入
			// 如果新的数字加入右边 则把栈顶pop出的数字加入左堆 然后操作右堆
			if (left_priority_queue.size()==0){
				left_priority_queue.push(num);
				return ;
			}

			long benchmark;
			benchmark = right_priority_queue.top();
			if (num>=benchmark){
				right_priority_queue.pop();
				left_priority_queue.push(benchmark);
				right_priority_queue.push(num);
			}
			else{
				left_priority_queue.push(num);
			}
		}
		else{
			// 左堆比右堆大一
			// 如果新的数字加入左边 则把栈顶pop而后加入右堆
			// 如果新数字直接加入右边 则直接加入
			long benchmark;
			benchmark = left_priority_queue.top();
			if (num>=benchmark)
				right_priority_queue.push(num);
			else{
				left_priority_queue.pop();
				right_priority_queue.push(benchmark);
				left_priority_queue.push(num);
			}
		}
		
	}

	// Returns the median of current data stream
	double findMedian() {
		if (left_priority_queue.empty() && right_priority_queue.empty())
			return 0.0;
		if (left_priority_queue.size() == right_priority_queue.size())
			return ((double) left_priority_queue.top() + (double) right_priority_queue.top())/2.0;
		return (double) left_priority_queue.top();
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(){
	MedianFinder mf;
	mf.addNum(1);
	//mf.addNum(2);
	cout << mf.findMedian() << endl;
	//mf.addNum(3);
	//cout << mf.findMedian() << endl;
}
