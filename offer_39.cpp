/*剑指offer —— 39 平衡二叉树
描述：输入一棵二叉树，判断该二叉树是否是平衡二叉树。*/

class Solution {
public:
	int getHeight(TreeNode* t)
	{
		if (t == NULL) return 0;
		return max(getHeight(t->left), getHeight(t->right)) + 1;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) return true;
		int leftH = getHeight(pRoot->left);
		int rightH = getHeight(pRoot->right);
		int diff = leftH - rightH;
		if (diff < -1 || diff>1) return false;
		else
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->left);
	}
};