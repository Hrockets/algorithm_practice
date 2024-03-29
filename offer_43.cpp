/*剑指offer —— 43 左旋转字符串
描述：
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
*/
class Solution {
public:
	string LeftRotateString(string str, int n) {

		int len = str.length();
		if (len == 0) return "";
		n = n % len;
		str += str;
		return str.substr(n, len);
	}
};