/*剑指offer —— 36 两个链表的第一个公共结点
描述：输入两个链表，找出它们的第一个公共结点。*/

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)return NULL;
		//首先遍历两个链表获取长度
		ListNode *pNode1 = pHead1, *pNode2 = pHead2;
		int listLength1 = 0, listLength2 = 0;
		while (pNode1 != NULL) {
			++listLength1;
			pNode1 = pNode1->next;
		}
		while (pNode2 != NULL) {
			++listLength2;
			pNode2 = pNode2->next;
		}
		//比较长度，长的先走dist步
		pNode1 = pHead1;
		pNode2 = pHead2;
		if (listLength1 > listLength2) {
			for (int i = 0; i < listLength1 - listLength2; i++)
				pNode1 = pNode1->next;
		}
		else if (listLength1 < listLength2) {
			for (int i = 0; i < listLength2 - listLength1; i++)
				pNode2 = pNode2->next;
		}
		while (pNode1 != NULL && pNode2 != NULL && pNode1 != pNode2) {
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
	}
};