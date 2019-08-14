/*��ָoffer ���� 18 �������ľ���
���������������Ķ�����������任ΪԴ�������ľ���
�������ľ����壺Դ������
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9 11
		���������
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
			//���������ӽڵ�
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