/*��ָoffer ���� 24 �������к�Ϊĳһֵ��·��
����������һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/

class Solution {
public:
	vector<vector<int> >res;
	vector<int> tmp;
	void dfs(TreeNode* node, int num)
	{
		tmp.push_back(node->val);
		if (num - node->val == 0 && !node->left && !node->right)
			res.push_back(tmp);
		else {
			if (node->left) dfs(node->left, num - node->val);
			if (node->right) dfs(node->right, num - node->val);
		}
		tmp.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root) dfs(root, expectNumber);
		return res;
	}
};