/*��ָoffer ���� 25 ��������ĸ���
����������һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/

/*
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{

		if (pHead == NULL) return NULL;
		RandomListNode* current = pHead;
		while (current != NULL) {
			RandomListNode* node = new RandomListNode(current->label);
			node->next = current->next;
			current->next = node;
			current = node->next;//������һ���ڵ�
		}

		//����randomָ��
		current = pHead;
		while (current != NULL) {
			if (current->random != NULL)
				current->next->random = current->random->next;
			current = current->next->next;
		}

		//���ɸ�������
		RandomListNode *temp, *pNewHead;
		pNewHead = pHead->next;

		current = pHead;
		temp = pNewHead;
		while (current != NULL) {
			current->next = current->next->next;
			if (temp->next != NULL)
				temp->next = temp->next->next;
			temp = temp->next;
			current = current->next;
		}
		return pNewHead;
	}
};