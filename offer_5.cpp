/*剑指offer —— 5 用两个栈实现队列
描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型
*/

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int a;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				a = stack1.top();
				stack1.pop();
				stack2.push(a);
			}
		}
		a = stack2.top();
		stack2.pop();
		return a;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};