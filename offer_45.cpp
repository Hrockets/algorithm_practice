/*剑指offer —— 45 扑克牌顺子
描述：A看作1,J为11,Q为12,K为13,大小王是0,
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,
如果牌能组成顺子就输出true，否则就输出false.
*/

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {

		if (numbers.size() != 5) return false;

		int* d = new int[14];
		d[0] = -5;
		int len = numbers.size();
		int max = -1;
		int min = 14;
		for (int i = 0; i < len; i++) {
			d[numbers[i]]++;
			if (numbers[i] == 0)//大小王
				continue;
			if (numbers[i] < 0 || numbers[i] >= 14) 
				return false;
			if (d[numbers[i]] > 1)//顺子里牌唯一
				return false;
			if (numbers[i] > max) {
				max = numbers[i];
			} if (numbers[i] < min) {
				min = numbers[i];
			}
		}
		if (max - min < 5)//顺子的范围限制
			return true;
		return false;
	}
};