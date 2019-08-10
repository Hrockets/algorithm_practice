/*剑指offer —— 60 把二叉树打印成多行
描述：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。*/

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> >res;
		if (pRoot == NULL) return res;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			int s = q.size();//每层结点记录
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