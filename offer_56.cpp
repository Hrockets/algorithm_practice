/*剑指offer —— 56 删除链表中重复的结点
描述：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return pHead;
		else
		{
			//新建一个节点，防止头结点要被删除
			ListNode* newHead = new ListNode(-1);
			newHead->next = pHead;
			ListNode* pre = newHead;
			ListNode* p = pHead;
			ListNode* next = NULL;
			while (p != NULL && p->next != NULL)
			{
				next = p->next;
				if (p->val == next->val)//如果当前节点的值和下一个节点的值相等
				{
					while (next != NULL && next->val == p->val)//向后重复查找
						next = next->next;
					pre->next = next;//指针赋值，就相当于删除
					p = next;
				}
				else//如果当前节点和下一个节点值不等，则向后移动一位
				{
					pre = p;
					p = p->next;
				}
			}
			return newHead->next;//返回头结点的下一个节点
		}
	}
};