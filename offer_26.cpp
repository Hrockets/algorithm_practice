/*��ָoffer ���� 26 ������������˫������
����������һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/

class Solution {
public:
	//˫����������ͷ�����ұ�ͷ�ڵ�
	TreeNode* leftHead = NULL;
	TreeNode* rightHead = NULL;

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//�ݹ����Ҷ�ӽڵ�����ҽڵ㷵��null
		if (pRootOfTree == NULL) return NULL;
		//��һ������ʱ������ʹ�����Ҷ�ӽڵ�Ϊ�����һ���ڵ�
		Convert(pRootOfTree->left);
		if (rightHead == NULL) {
			leftHead = rightHead = pRootOfTree;
		}
		else {
			//�Ѹ��ڵ���뵽˫�������ұߣ�rightHead����ƶ�
			rightHead->right = pRootOfTree;
			pRootOfTree->left = rightHead;
			rightHead = pRootOfTree;
		}
		//����Ҷ�ӽڵ�Ҳ���뵽˫������rightHead��ȷ����ֱ�Ӳ��룩
		Convert(pRootOfTree->right);
		//�������ͷ���
		return leftHead;
	}
};