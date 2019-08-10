/*��ָoffer ���� 39 ƽ�������
����������һ�ö��������жϸö������Ƿ���ƽ���������*/

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