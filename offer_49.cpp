/*剑指offer —— 49 把字符串转换成整数
描述：将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0。
*/

class Solution {
public:
	int StrToInt(string str) {

		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') {//处理负号
			symbol = -1;
			str[0] = '0'; //这里是‘0’ 不是0
		}
		else if (str[0] == '+') {//处理正号
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] < '0' || str[i] > '9') {
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol * sum;
	}
};


