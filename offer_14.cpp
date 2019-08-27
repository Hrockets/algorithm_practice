/*��ָoffer ���� 14 �����е�����k�����
����������һ����������������е�����k����㡣
*/

/*�������Ŀռ�ջ ��ջ������k�����*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0) return NULL;
		stack<ListNode*> st;
		ListNode* node = pListHead;
		ListNode* t = NULL;

		while (node)
		{
			st.push(node);
			node = node->next;
		}
		int count = 0;
		while (!st.empty())
		{
			t = st.top();
			count++;
			if (count == k) return t;
			st.pop();
		}
		return NULL;
	}
};
/*˫ָ�뷨 ǰָ������k-1��ǰ��ָ����һ���ߣ�ֱ��ǰָ���ѵ�β��㣬��ָ��ָ��Ҫ��Ľ�㷵�ؼ���*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0) {
			return NULL;
		}
		ListNode *phead = pListHead;
		ListNode *pBehind = pListHead;
		for (unsigned int i = 0; i < k - 1; i++) {
			if (phead->next != NULL) {
				phead = phead->next;
			}
			else {
				return NULL;
			}
		}
		while (phead->next != NULL) {
			phead = phead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};