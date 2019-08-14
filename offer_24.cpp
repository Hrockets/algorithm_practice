/*剑指offer —— 24 二叉树中和为某一值的路径
描述：输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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