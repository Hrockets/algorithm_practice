/*剑指offer —— 59 按之字形顺序打印二叉树
描述：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
层序遍历的应用*/

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