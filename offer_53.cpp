/*剑指offer —— 53 表示数值的字符串
描述：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

class Solution {
public:
	bool isNumeric(char* string)
	{
		bool iserror = false;
		int point_num = 0, e_flag = 0;
		for (int i = 0; string[i] != '\0'; i++)
		{
			//+、-在开头或在E、e后面
			if (string[i] == '+' || string[i] == '-')
			{
				if (i != 0 && ((string[i - 1] != 'e') && (string[i - 1] != 'E')))
				{
					iserror = true;
					break;
				}
			}
			//小数点只有一个并且Ee后面不可以跟小数
			if (string[i] == '.' && (point_num != 0 || e_flag == 1))
			{
				iserror = true;
				break;
			}
			//计算小数点个数
			if (string[i] == '.'&&point_num == 0)
				point_num++;
			//出现除Ee以外的字母
			if ((string[i] >= 'a'&&string[i] <= 'z'&&string[i] != 'e')
				|| (string[i] >= 'A'&&string[i] <= 'Z'&&string[i] != 'E'))
			{
				iserror = true;
				break;
			}
			//记录Ee出现，Ee后面必须有值
			if ((string[i] == 'e') || (string[i] == 'E'))
			{
				e_flag = 1;
				if (string[i + 1] == '\0')
				{
					iserror = true;
					break;
				}
			}
		}
		if (iserror) return false;
		else return true;
	}
};