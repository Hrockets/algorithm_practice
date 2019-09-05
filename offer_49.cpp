/*��ָoffer ���� 49 ���ַ���ת��������
��������һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�
����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
*/

class Solution {
public:
	int StrToInt(string str) {

		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') {//������
			symbol = -1;
			str[0] = '0'; //�����ǡ�0�� ����0
		}
		else if (str[0] == '+') {//��������
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


