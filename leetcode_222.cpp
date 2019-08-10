//leetcode 222 完全二叉树的节点个数

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		TreeNode* cur = root;
		int ldepth = 0, rdepth = 0;
		//左子树深度
		while (cur != NULL) {
			ldepth++;
			cur = cur->left;
		}
		cur = root;
		//右子树深度
		while (cur != NULL) {
			rdepth++;
			cur = cur->right;
		}
		if (ldepth == rdepth) return (pow(2, ldepth) - 1);
		else return (countNodes(root->left) + countNodes(root->right) + 1);
	}
};
