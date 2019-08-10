/*��ָoffer ���� 38 �����������
����������һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·����
�·���ĳ���Ϊ������ȡ�*/

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