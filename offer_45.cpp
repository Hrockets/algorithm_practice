/*��ָoffer ���� 45 �˿���˳��
������A����1,JΪ11,QΪ12,KΪ13,��С����0,
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,
����������˳�Ӿ����true����������false.
*/

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {

		if (numbers.size() != 5) return false;

		int* d = new int[14];
		d[0] = -5;
		int len = numbers.size();
		int max = -1;
		int min = 14;
		for (int i = 0; i < len; i++) {
			d[numbers[i]]++;
			if (numbers[i] == 0)//��С��
				continue;
			if (numbers[i] < 0 || numbers[i] >= 14) 
				return false;
			if (d[numbers[i]] > 1)//˳������Ψһ
				return false;
			if (numbers[i] > max) {
				max = numbers[i];
			} if (numbers[i] < min) {
				min = numbers[i];
			}
		}
		if (max - min < 5)//˳�ӵķ�Χ����
			return true;
		return false;
	}
};