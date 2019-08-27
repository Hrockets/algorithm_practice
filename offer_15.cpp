/*剑指offer —— 15 反转链表
描述：输入一个链表，反转链表后，输出新链表的表头。
*/

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {

		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* head = new ListNode(0);//头结点指针
		head->next = pHead;//指向头结点

		ListNode* cur = NULL;
		cur = head->next->next;
		head->next->next = NULL;

		ListNode* next = NULL;
		while (cur != NULL) {
			next = cur->next;
			cur->next = head->next;
			head->next = cur;//更新头结点
			cur = next;
		}
		return head->next;
	}
};