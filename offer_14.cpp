/*剑指offer —— 14 链表中倒数第k个结点
描述：输入一个链表，输出该链表中倒数第k个结点。
*/

/*申请额外的空间栈 从栈顶弹出k个结点*/
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
/*双指针法 前指针先走k-1，前后指针在一起走，直到前指针已到尾结点，后指针指向要求的结点返回即可*/
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