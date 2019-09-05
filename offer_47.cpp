/*剑指offer —— 47 求1+2+3+…+n
描述：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

class Solution {
public:
	int Sum_Solution(int n) {

		//int sum = n;
		//bool flag = (sum>0)&&((sum+=Sum_Solution(--n))>0);//>优先级比+=高
		//return sum;
		return ((pow(n, 2) + n) / 2);
	}
};


