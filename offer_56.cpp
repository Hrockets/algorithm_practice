/*��ָoffer ���� 56 ɾ���������ظ��Ľ��
��������һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻������
��������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return pHead;
		else
		{
			//�½�һ���ڵ㣬��ֹͷ���Ҫ��ɾ��
			ListNode* newHead = new ListNode(-1);
			newHead->next = pHead;
			ListNode* pre = newHead;
			ListNode* p = pHead;
			ListNode* next = NULL;
			while (p != NULL && p->next != NULL)
			{
				next = p->next;
				if (p->val == next->val)//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ���
				{
					while (next != NULL && next->val == p->val)//����ظ�����
						next = next->next;
					pre->next = next;//ָ�븳ֵ�����൱��ɾ��
					p = next;
				}
				else//�����ǰ�ڵ����һ���ڵ�ֵ���ȣ�������ƶ�һλ
				{
					pre = p;
					p = p->next;
				}
			}
			return newHead->next;//����ͷ������һ���ڵ�
		}
	}
};