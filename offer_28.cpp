/*��ָoffer ���� 28 �����г��ִ�������һ�������
��������������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {


		int n = numbers.size();
		if (n == 0) return 0;

		int num = numbers[0], count = 1;
		for (int i = 1; i < n; i++) {
			if (numbers[i] == num) count++;
			else count--;
			if (count == 0) {
				num = numbers[i];
				count = 1;
			}
		}
		
		count = 0;
		for (int i = 0; i < n; i++) {
			if (numbers[i] == num) count++;
		}
		if (count * 2 > n) return num;
		return 0;
	}
};