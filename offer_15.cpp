/*��ָoffer ���� 15 ��ת����
����������һ��������ת��������������ı�ͷ��
*/

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {

		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* head = new ListNode(0);//ͷ���ָ��
		head->next = pHead;//ָ��ͷ���

		ListNode* cur = NULL;
		cur = head->next->next;
		head->next->next = NULL;

		ListNode* next = NULL;
		while (cur != NULL) {
			next = cur->next;
			cur->next = head->next;
			head->next = cur;//����ͷ���
			cur = next;
		}
		return head->next;
	}
};