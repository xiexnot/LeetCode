#include <algorithm>

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		// 重叠 rectangle
		// left bottom node [P,Q]
		// right top node [R,S]
		// 画图可以得知 新矩阵的点和原来矩阵的点之间的转换关系

		// 最后的面积就是 两个矩阵面积之和减去重叠部分
		int P,Q,R,S;
		P = max(A,E);
		Q = max(B,F);
		R = min(C,G);
		S = min(D,H);
		if (P<=R&&Q<=S)
			return (C-A)*(D-B) + (G-E)*(H-F) - (R-P)*(S-Q);
		else
			return (C-A)*(D-B) + (G-E)*(H-F);
	}
};