/*剑指offer —— 7 斐波那契数列
描述：大家都知道斐波那契数列，现在要求输入一个整数n，
请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		long long prere = 0;
		long long pre = 1;
		long long cur = 0;
		for (int i = 2; i <= n; i++) {
			cur = prere + pre;
			prere = pre;
			pre = cur;
		}
		return cur;
	}
};