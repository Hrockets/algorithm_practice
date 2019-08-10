/*剑指offer —— 38 二叉树的深度
描述：输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
最长路径的长度为树的深度。*/

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) return 0;

		queue<TreeNode*> q;
		int depth = 0;
		q.push(pRoot);
		while (!q.empty())
		{
			int len = q.size();
			depth++;
			while (len--)
			{
				TreeNode* t = q.front();
				q.pop();
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return depth;
	}
};