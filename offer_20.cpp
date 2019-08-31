/*��ָoffer ���� 20 ����min������ջ
����������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
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