/*��ָoffer ���� 12 ��ֵ�������η�
����������һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
��֤base��exponent��ͬʱΪ0
*/

class Solution {
public:
	double Power(double base, int exponent) {

		double res = 1.0;
		if (base == 0)
			return 0;
		if (exponent == 0)
			return 1;
		if (exponent < 0)
			base = 1.0 / base;
		while (exponent) {
			res *= base;
			exponent = (exponent > 0) ? (--exponent) : (++exponent);
		}
		return res;
	}
};