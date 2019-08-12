/*剑指offer —— 3 替换空格
描述：请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL) return;//边界检查

		int blank_cnt = 0;
		int original_len = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			original_len++;
			if (str[i] == ' ')
				blank_cnt++;
		}

		int len = original_len + 2 * blank_cnt;
		if (len + 1 > length) return;//超过字符串数组

		// 替换空格
		char* pStr1 = str + original_len;// 字符指针指向原始字符串的末尾
		char* pStr2 = str + len;           // 字符指针指向替换后字符串的末尾

		while (pStr1 != pStr2)         // 替换结束的条件
		{
			if (*pStr1 == ' ')
			{
				*pStr2-- = '0';
				*pStr2-- = '2';
				*pStr2-- = '%';
			}
			else
			{
				*pStr2-- = *pStr1;
			}
			--pStr1;
		}
	}
};