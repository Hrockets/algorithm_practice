//leetcode 199 ������������ͼ
/*˼·���ǲ��������˼·*/
vector<int> rightSideView(TreeNode* root) {

	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		//ȡÿһ������Ԫ��
		res.push_back(q.back()->val);
		int size = q.size();//ÿһ��
		while (size--) {
			TreeNode* t = q.front();
			q.pop();
			if (t->left != NULL) q.push(t->left);
			if (t->right != NULL) q.push(t->right);
		}
	}
	return res;
}
