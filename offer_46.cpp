/*��ָoffer ���� 46 �����ǵ���Ϸ��ԲȦ�����ʣ�µ�����
������ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:
����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��
,��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,
���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)
���û��С���ѣ��뷵��-1
*/

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1) {
			return -1;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++) v[i] = i;
		int out_cnt = 0, cnt = n, cur_index = 0;
		while (out_cnt < n - 1) {
			if (cur_index + m > cnt) {
				if ((cur_index + m) % cnt == 0)
					cur_index = cnt - 1;
				else cur_index = (cur_index + m) % cnt - 1;
			}
			else
				cur_index = cur_index + m - 1;
			out_cnt++; cnt--;
			cout << *(v.begin() + cur_index) << endl;
			v.erase(v.begin() + cur_index);
		}
		return v[0];
	}
};

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		// invalid input
		if (n <= 0 || m < 0)
			return -1;

		// if there are only one integer in the circle initially,
		// of course the last remaining one is 0
		int lastinteger = 0;

		// find the last remaining one in the circle with n integers
		for (int i = 2; i <= n; i++)
			lastinteger = (lastinteger + m) % i;

		return lastinteger;
	}
};