/*��ָoffer ���� 8 ��̨��
������һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/

class Solution {
public:
	//f(i)=f(i-1)+f(i-2)
	int jumpFloor(int number) {
		if (number == 0) return 0;
		if (number == 1) return 1;
		if (number == 2) return 2;
		int prere = 1, pre = 2, cur = 0;
		for (int i = 3; i <= number; i++)
		{
			cur = prere + pre;//��̬�滮
			prere = pre;
			pre = cur;
		}
		return cur;
	}
};