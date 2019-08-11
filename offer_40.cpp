/*剑指offer —— 40 数组中只出现一次的数字
描述：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
	//思路：用异或的特性，A^A=0 0^X=X;以及异或的交换律特性。
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int x = 0, len = data.size();
		for (int i = 0; i < len; ++i)
			x ^= data[i];//x保存所有元素异或的结果
		int n = 1;
		while ((x & n) == 0)//找出最右边第1个不为0的位置
			n = n << 1;
		int x1 = 0, x2 = 0;
		for (int i = 0; i < len; ++i)
			if (data[i] & n)//根据第一个不为0的位置重新将数组进行划分
				x1 ^= data[i];
			else
				x2 ^= data[i];
		*num1 = x1;
		*num2 = x2;
		return;
	}
};