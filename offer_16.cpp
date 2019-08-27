/*剑指offer —— 16 合并两个排序的链表
描述：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		ListNode* current = NULL;
		ListNode* mergeHead = NULL;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val <= pHead2->val)
			{

				if (mergeHead == NULL) {
					mergeHead = current = pHead1;
				}
				else {
					current->next = pHead1;
					current = current->next;
				}
				pHead1 = pHead1->next;
			}
			else {
				if (mergeHead == NULL) {
					mergeHead = current = pHead2;
				}
				else {
					current->next = pHead2;
					current = current->next;
				}
				pHead2 = pHead2->next;
			}
		}
		if (pHead1 == NULL) {
			current->next = pHead2;
		}
		else {
			current->next = pHead1;
		}
		return mergeHead;

	}
};