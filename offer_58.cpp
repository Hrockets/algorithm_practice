/*��ָoffer ���� 58 �ԳƵĶ�����
��������ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�*/

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