//leetcode 222 ��ȫ�������Ľڵ����

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		TreeNode* cur = root;
		int ldepth = 0, rdepth = 0;
		//���������
		while (cur != NULL) {
			ldepth++;
			cur = cur->left;
		}
		cur = root;
		//���������
		while (cur != NULL) {
			rdepth++;
			cur = cur->right;
		}
		if (ldepth == rdepth) return (pow(2, ldepth) - 1);
		else return (countNodes(root->left) + countNodes(root->right) + 1);
	}
};
