/*剑指offer —— 13 调整数组顺序使奇数位于偶数前面
描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*申请额外的空间从原来的数组里先分离奇数在分偶数*/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> res;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 1)
				res.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
				res.push_back(array[i]);
		}
		array = res;
	}
};


/*原地排序 运用插排思想 记录奇数的前面位置*/
void reOrderArray(vector<int> &array) {
	//相对位置不变，稳定性
	//插入排序的思想
	int m = array.size();
	int k = 0;//记录已经摆好位置的奇数的个数
	for (int i = 0; i < m; i++) {
		if (array[i] % 2 == 1) {
			int j = i;
			while (j > k) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				j--;
			}
			k++;
		}
	}
}