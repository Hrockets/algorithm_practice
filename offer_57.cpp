/*剑指offer —— 57 二叉树的下一个结点
描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;//指向父结点的指针。
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};*/

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL) return NULL;
		//若右结点存在，则为右子树最左子节点
		if (pNode->right != NULL) {
			pNode = pNode->right;
			while (pNode->left != NULL) pNode = pNode->left;
			return pNode;
		}
		//若右结点不存在，则向上搜寻找到当前结点为父节点的左孩子，则返回该父节点
		while (pNode->next != NULL) {
			if (pNode->next->left == pNode) return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};