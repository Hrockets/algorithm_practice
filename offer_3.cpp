/*��ָoffer ���� 3 �滻�ո�
��������ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL) return;//�߽���

		int blank_cnt = 0;
		int original_len = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			original_len++;
			if (str[i] == ' ')
				blank_cnt++;
		}

		int len = original_len + 2 * blank_cnt;
		if (len + 1 > length) return;//�����ַ�������

		// �滻�ո�
		char* pStr1 = str + original_len;// �ַ�ָ��ָ��ԭʼ�ַ�����ĩβ
		char* pStr2 = str + len;           // �ַ�ָ��ָ���滻���ַ�����ĩβ

		while (pStr1 != pStr2)         // �滻����������
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