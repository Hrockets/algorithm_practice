/*剑指offer —— 25 复杂链表的复制
描述：输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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
			current = node->next;//处理下一个节点
		}

		//处理random指针
		current = pHead;
		while (current != NULL) {
			if (current->random != NULL)
				current->next->random = current->random->next;
			current = current->next->next;
		}

		//生成复制链表
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