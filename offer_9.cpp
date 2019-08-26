/*剑指offer —— 9 变态跳台阶
描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。

当n=1时，结果为1；
当n=2时，结果为2；
当n=3时，结果为4；
以此类推，我们使用数学归纳法不难发现，跳法f(n)=2^(n-1)。
*/

class Solution {
public:
	int jumpFloorII(int number) {

		int result = 1;
		while (number-- > 1) {
			result *= 2;
		}
		return result;
	}
};