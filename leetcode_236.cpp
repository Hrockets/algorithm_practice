//leetcode 236 ������p,q��������Ƚ��
/*˵�������нڵ��ֵ����Ψһ�ġ�
		����p��q Ϊ��ͬ�ڵ��Ҿ������ڸ����Ķ������С�*/
		/*��һ�����  �����ڶ�������
		  �ڶ������  ֻ����������/��������ĳһ�����Ϊ���Ƚ��
		  ���������  һ�����ڵ�����Һ���*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root == p || root == q) return root;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (!left && !right) return NULL;
	else if (left && !right) return left;
	else if (!left&&right) return right;

	return root;
}
