/*��ָoffer ���� 53 ��ʾ��ֵ���ַ���
��������ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/

class Solution {
public:
	bool isNumeric(char* string)
	{
		bool iserror = false;
		int point_num = 0, e_flag = 0;
		for (int i = 0; string[i] != '\0'; i++)
		{
			//+��-�ڿ�ͷ����E��e����
			if (string[i] == '+' || string[i] == '-')
			{
				if (i != 0 && ((string[i - 1] != 'e') && (string[i - 1] != 'E')))
				{
					iserror = true;
					break;
				}
			}
			//С����ֻ��һ������Ee���治���Ը�С��
			if (string[i] == '.' && (point_num != 0 || e_flag == 1))
			{
				iserror = true;
				break;
			}
			//����С�������
			if (string[i] == '.'&&point_num == 0)
				point_num++;
			//���ֳ�Ee�������ĸ
			if ((string[i] >= 'a'&&string[i] <= 'z'&&string[i] != 'e')
				|| (string[i] >= 'A'&&string[i] <= 'Z'&&string[i] != 'E'))
			{
				iserror = true;
				break;
			}
			//��¼Ee���֣�Ee���������ֵ
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