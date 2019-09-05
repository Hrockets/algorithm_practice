/*剑指offer —— 48 不用加减乘除的加法
描述：写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0) {
			int sum = num1 ^ num2;//不算进位的相加
			int carray = (num1 & num2) << 1;//计算进位
			num1 = sum;
			num2 = carray;
		}
		return num1;
		//if(num1>0){
			//while(num1--!=0)
				//num2++;
		//}
		//else if(num1<0){
			//while(num1++!=0)
				//num2--;
		//}
		//return num2;
	}
};


