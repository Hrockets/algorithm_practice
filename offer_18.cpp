/*剑指offer —— 18 二叉树的镜像
描述：操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：源二叉树
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		镜像二叉树
			8
		   /  \
		  10   6
		 / \  / \
		11 9 7  5
*/

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		queue<TreeNode* > q;
		q.push(pRoot);
		while (!q.empty()) {
			TreeNode * t = q.front();
			q.pop();
			//交换左右子节点
			if (t->left != NULL || t->right != NULL) {
				TreeNode * temp = t->left;
				t->left = t->right;
				t->right = temp;
			}
			if (t->left != NULL) q.push(t->left);
			if (t->right != NULL) q.push(t->right);
		}
	}
};