/*��ָoffer ���� 40 ������ֻ����һ�ε�����
������һ�����������������������֮�⣬���������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�
*/

class Solution {
public:
	//˼·�����������ԣ�A^A=0 0^X=X;�Լ����Ľ��������ԡ�
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int x = 0, len = data.size();
		for (int i = 0; i < len; ++i)
			x ^= data[i];//x��������Ԫ�����Ľ��
		int n = 1;
		while ((x & n) == 0)//�ҳ����ұߵ�1����Ϊ0��λ��
			n = n << 1;
		int x1 = 0, x2 = 0;
		for (int i = 0; i < len; ++i)
			if (data[i] & n)//���ݵ�һ����Ϊ0��λ�����½�������л���
				x1 ^= data[i];
			else
				x2 ^= data[i];
		*num1 = x1;
		*num2 = x2;
		return;
	}
};