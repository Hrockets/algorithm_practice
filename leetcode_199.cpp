//leetcode 199 二叉树的右视图
/*思路还是层序遍历的思路*/
vector<int> rightSideView(TreeNode* root) {

	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		//取每一层最后的元素
		res.push_back(q.back()->val);
		int size = q.size();//每一层
		while (size--) {
			TreeNode* t = q.front();
			q.pop();
			if (t->left != NULL) q.push(t->left);
			if (t->right != NULL) q.push(t->right);
		}
	}
	return res;
}
