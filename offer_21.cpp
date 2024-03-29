/*剑指offer —— 21 栈的压入、弹出序列
描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty()) return false;
		int j = 0;
		for (int i = 0; i < pushV.size(); i++) {
			stackData.push(pushV[i]);//模拟入栈
			while (j < popV.size() && stackData.top() == popV[j]) {//模拟出栈
				stackData.pop();
				j++;
			}
		}
		return stackData.empty();//如果出栈顺序正确，栈中无元素
	}
private:
	stack<int> stackData;
};