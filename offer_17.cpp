/*��ָoffer ���� 17 �����ӽṹ
�������������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*/

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;
		//����Ϊ�յĻ���ȥ�жϣ���Ϊ������������һ����������
		if (pRoot1 != NULL && pRoot2 != NULL) {
			//��ȣ����������һ�������ݹ��ж�
			if (pRoot1->val == pRoot2->val)
				res = doTree1ContainsTree2(pRoot1, pRoot2);
			//����������������Ļ������������һ����ȵĽ�㣬��ȥ����
			if (!res)
				res = HasSubtree(pRoot1->left, pRoot2);
			if (!res)
				res = HasSubtree(pRoot1->right, pRoot2);
		}
		return res;
	}

	bool doTree1ContainsTree2(TreeNode* root1, TreeNode* root2) {
		//�ݹ����1�������Ѿ��ж������������������������̶�Ϊtrue�����շ���true
		if (root2 == NULL)
			return true;
		//�ݹ����2��������û�գ��������ߵ����ˣ���ô�϶��ǲ��������ṹ��
		if (root1 == NULL)
			return false;
		//�ݹ����3���������Ľ��ֵ����ȵĻ�ֹͣ
		if (root1->val != root2->val)
			return false;
		//�ݹ�
		return doTree1ContainsTree2(root1->left, root2->left) && doTree1ContainsTree2(root1->right, root2->right);
	}
};