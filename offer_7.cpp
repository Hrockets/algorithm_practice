/*��ָoffer ���� 7 쳲���������
��������Ҷ�֪��쳲��������У�����Ҫ������һ������n��
�������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n<=39
*/

class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		long long prere = 0;
		long long pre = 1;
		long long cur = 0;
		for (int i = 2; i <= n; i++) {
			cur = prere + pre;
			prere = pre;
			pre = cur;
		}
		return cur;
	}
};