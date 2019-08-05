//leetcode 236 二叉树p,q的最近祖先结点
/*说明：所有节点的值都是唯一的。
		并且p、q 为不同节点且均存在于给定的二叉树中。*/
		/*第一种情况  不存在二叉树中
		  第二种情况  只存在左子树/右子树，某一个结点为祖先结点
		  第三种情况  一个根节点的左右孩子*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root == p || root == q) return root;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (!left && !right) return NULL;
	else if (left && !right) return left;
	else if (!left&&right) return right;

	return root;
}
