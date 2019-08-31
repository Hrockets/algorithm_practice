/*剑指offer —— 20 包含min函数的栈
描述：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
public:
	void push(int value) {
		data.push(value);
		if (Min.empty()) Min.push(value);
		if (Min.top() > value) Min.push(value);
	}
	void pop() {
		if (Min.top() == data.top()) {
			Min.pop();
		}
		data.pop();
	}
	int top() {
		return data.top();
	}
	int min() {
		return Min.top();
	}
private:
	stack<int> data;
	stack<int> Min;
};