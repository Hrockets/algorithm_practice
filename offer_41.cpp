/*��ָoffer ���� 41 ��ΪS��������������
������С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
*/

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > result;
		// ��λָ��͵�λָ��
		int phigh = 2, plow = 1;

		// ��ֹ������phigh����plow
		while (phigh > plow) {
			// ��ǰ�ͣ�ʹ����͹�ʽs = (a+b) * n / 2
			int curSum = (plow + phigh) * (phigh - plow + 1) >> 1;
			if (curSum < sum) {
				phigh++;
			}
			if (curSum == sum) {
				vector<int> temp;
				for (int i = plow; i <= phigh; i++) {
					temp.push_back(i);
				}
				result.push_back(temp);
				plow++;
			}
			if (curSum > sum) {
				plow++;
			}
		}
		return result;
	}
};