/*剑指offer —— 58 对称的二叉树
描述：请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。*/

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL) return true;
		queue<TreeNode*> q;
		q.push(pRoot->left);
		q.push(pRoot->right);
		while (!q.empty()) {
			TreeNode* left = q.front(); q.pop();
			TreeNode* right = q.front(); q.pop();
			if (left == NULL && right == NULL) continue;
			if (left == NULL || right == NULL) return false;
			if (left->val != right->val) return false;
			q.push(left->left);
			q.push(right->right);
			q.push(left->right);
			q.push(right->left);
		}
		return true;
	}
};