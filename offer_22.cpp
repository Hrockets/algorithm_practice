/*��ָoffer ���� 22 ���ϵ��´�ӡ������
�������������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*/

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* n = q.front();
			res.push_back(n->val);

			if (n->left != NULL) q.push(n->left);
			if (n->right != NULL) q.push(n->right);
			q.pop();
		}
		return res;
	}
};