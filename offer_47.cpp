/*��ָoffer ���� 47 ��1+2+3+��+n
��������1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/

class Solution {
public:
	int Sum_Solution(int n) {

		//int sum = n;
		//bool flag = (sum>0)&&((sum+=Sum_Solution(--n))>0);//>���ȼ���+=��
		//return sum;
		return ((pow(n, 2) + n) / 2);
	}
};


