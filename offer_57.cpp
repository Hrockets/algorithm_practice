/*��ָoffer ���� 57 ����������һ�����
����������һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;//ָ�򸸽���ָ�롣
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};*/

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL) return NULL;
		//���ҽ����ڣ���Ϊ�����������ӽڵ�
		if (pNode->right != NULL) {
			pNode = pNode->right;
			while (pNode->left != NULL) pNode = pNode->left;
			return pNode;
		}
		//���ҽ�㲻���ڣ���������Ѱ�ҵ���ǰ���Ϊ���ڵ�����ӣ��򷵻ظø��ڵ�
		while (pNode->next != NULL) {
			if (pNode->next->left == pNode) return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};