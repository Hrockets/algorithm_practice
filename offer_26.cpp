/*剑指offer —— 26 二叉搜索树与双向链表
描述：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

class Solution {
public:
	//双向链表的左边头结点和右边头节点
	TreeNode* leftHead = NULL;
	TreeNode* rightHead = NULL;

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//递归调用叶子节点的左右节点返回null
		if (pRootOfTree == NULL) return NULL;
		//第一次运行时，它会使最左边叶子节点为链表第一个节点
		Convert(pRootOfTree->left);
		if (rightHead == NULL) {
			leftHead = rightHead = pRootOfTree;
		}
		else {
			//把根节点插入到双向链表右边，rightHead向后移动
			rightHead->right = pRootOfTree;
			pRootOfTree->left = rightHead;
			rightHead = pRootOfTree;
		}
		//把右叶子节点也插入到双向链表（rightHead已确定，直接插入）
		Convert(pRootOfTree->right);
		//返回左边头结点
		return leftHead;
	}
};