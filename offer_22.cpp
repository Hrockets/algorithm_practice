/*剑指offer —— 22 从上到下打印二叉树
描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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