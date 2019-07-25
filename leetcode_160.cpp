//leetcode 160 相交链表
/*编写一个程序，找到两个单链表相交的起始节点。*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA==NULL||headB==NULL) return NULL;
	int len1=0,len2=0;
	ListNode *phead1=headA,*phead2=headB;
	while(phead1){
		len1++;
		phead1=phead1->next;
	}
	while(phead2){
		len2++;
		phead2=phead2->next;
	}
	phead1=headA;
	phead2=headB;
	if(len1>len2){
		for(int i=0;i<(len1-len2);i++)
			phead1=phead1->next;
	}
	else{
		for(int i=0;i<(len2-len1);i++)
			phead2=phead2->next;
	}
	while(phead1){
		if(phead1==phead2) return phead1;
		phead1=phead1->next;
		phead2=phead2->next;
	}
	return NULL;
}
