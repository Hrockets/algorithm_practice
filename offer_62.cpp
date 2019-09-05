/*剑指offer —— 62 二叉搜索树的第k个结点
描述：给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
*/

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0) return NULL;
		stack<TreeNode*> st;
		int count = 0;
		TreeNode* node = pRoot;
		do {
			if (node != NULL)
			{
				st.push(node);
				node = node->left;
			}
			else {
				node = st.top();
				st.pop();
				count++;
				if (count == k)
					return node;
				node = node->right;
			}
		} while (node != NULL || !st.empty());
		return NULL;
	}
};