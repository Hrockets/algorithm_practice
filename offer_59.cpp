/*��ָoffer ���� 59 ��֮����˳���ӡ������
��������ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
���������Ӧ��*/

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		if (!pRoot) return res;
		queue<TreeNode*> q;
		q.push(pRoot);
		bool even = false;
		while (!q.empty()) {
			int size = q.size();
			vector<int> v;
			for (int i = 0; i < size; i++) {
				TreeNode* t = q.front();
				v.push_back(t->val);
				q.pop();
				if (t->left != NULL) q.push(t->left);
				if (t->right != NULL) q.push(t->right);
			}

			if (even) reverse(v.begin(), v.end());
			res.push_back(v);
			even = !even;
		}
		return res;
	}
};