/*��ָoffer ���� 3 ��β��ͷ��ӡ����
����������һ��������ӡһ�����������
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