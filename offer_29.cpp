/*剑指offer —— 29 最小的K个数
描述：输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
//堆排思想
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