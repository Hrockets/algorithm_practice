/*��ָoffer ���� 62 �����������ĵ�k�����
����������һ�ö��������������ҳ����еĵ�kС�Ľ�㡣
���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
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