/*��ָoffer ���� 29 ��С��K����
����������n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/
//����˼��
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

		priority_queue<int> Q;
		vector<int> res;
		if (input.size() < k || k <= 0) return res;
		for (int i = 0; i < input.size(); ++i) {
			if (Q.size() < k) Q.push(input[i]);
			else if (input[i] < Q.top()) {
				Q.pop();
				Q.push(input[i]);
			}
		}
		while (!Q.empty()) {
			res.push_back(Q.top());
			Q.pop();
		}
		return res;
	}
};