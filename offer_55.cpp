/*剑指offer —— 55 链表中环的入口结点
描述：给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL) return NULL;
		ListNode* fast = pHead->next->next;
		ListNode* slow = pHead->next;
		while (fast != slow)
		{
			if (fast == NULL || fast->next == NULL)
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = pHead;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};