/*剑指offer —— 8 跳台阶
描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
	//f(i)=f(i-1)+f(i-2)
	int jumpFloor(int number) {
		if (number == 0) return 0;
		if (number == 1) return 1;
		if (number == 2) return 2;
		int prere = 1, pre = 2, cur = 0;
		for (int i = 3; i <= number; i++)
		{
			cur = prere + pre;//动态规划
			prere = pre;
			pre = cur;
		}
		return cur;
	}
};