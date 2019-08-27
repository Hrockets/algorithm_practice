/*剑指offer —— 17 树的子结构
描述：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;
		//都不为空的话再去判断，因为空树不是任意一个树的子树
		if (pRoot1 != NULL && pRoot2 != NULL) {
			//相等，则进入另外一个函数递归判断
			if (pRoot1->val == pRoot2->val)
				res = doTree1ContainsTree2(pRoot1, pRoot2);
			//上面个不符合条件的话，则继续找下一个相等的结点，再去遍历
			if (!res)
				res = HasSubtree(pRoot1->left, pRoot2);
			if (!res)
				res = HasSubtree(pRoot1->right, pRoot2);
		}
		return res;
	}

	bool doTree1ContainsTree2(TreeNode* root1, TreeNode* root2) {
		//递归出口1：子树已经判断完毕了则结束，表明整个过程都为true，最终返回true
		if (root2 == NULL)
			return true;
		//递归出口2：子树还没空，父树先走到空了，那么肯定是不是子树结构的
		if (root1 == NULL)
			return false;
		//递归出口3：两个数的结点值不相等的话停止
		if (root1->val != root2->val)
			return false;
		//递归
		return doTree1ContainsTree2(root1->left, root2->left) && doTree1ContainsTree2(root1->right, root2->right);
	}
};