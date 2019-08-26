/*剑指offer —— 3 从尾到头打印链表
描述：输入一个链表，打印一个反序的链表。
*/

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int> nodes;
		vector<int> result;
		ListNode* node = head;
		while (node != NULL) {
			nodes.push(node->val);
			node = node->next;
		}

		while (!nodes.empty()) {
			result.push_back(nodes.top());
			nodes.pop();
		}
		return result;
	}
};