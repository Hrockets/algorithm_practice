/*��ָoffer ���� 63 �������е���λ��
��������εõ�һ���������е���λ����������������ж�����������ֵ��
��ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����*/

class Solution {

public:
	void Insert(int num)
	{
		count += 1;
		// Ԫ�ظ�����ż��ʱ,���󶥶ѶѶ�����С����
		if (count % 2 == 0) {
			big_heap.push(num);
			small_heap.push(big_heap.top());
			big_heap.pop();
		}
		else {
			small_heap.push(num);
			big_heap.push(small_heap.top());
			small_heap.pop();
		}
	}

	double GetMedian()
	{
		if (count & 0x1) {
			return big_heap.top();
		}
		else {
			return double((small_heap.top() + big_heap.top()) / 2.0);
		}
	}
private:
	int count = 0;
	priority_queue<int, vector<int>, less<int>> big_heap;        // ���һ���󶥶�
	priority_queue<int, vector<int>, greater<int>> small_heap;   // �ұ�һ��С����
	// �󶥶�����Ԫ�ؾ�С�ڵ���С���ѵ�����Ԫ��.
};