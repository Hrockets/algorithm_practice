/*��ָoffer ���� 60 �Ѷ�������ӡ�ɶ���
���������ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�*/

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> >res;
		if (pRoot == NULL) return res;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			int s = q.size();//ÿ�����¼
			vector<int> v;
			for (int i = 0; i < s; i++)
			{
				TreeNode* node = q.front();
				q.pop();
				if (node->left != NULL) q.push(node->left);
				if (node->right != NULL) q.push(node->right);
				v.push_back(node->val);
			}
			res.push_back(v);
		}
		return res;
	}
};