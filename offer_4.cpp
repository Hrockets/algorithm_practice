/*剑指offer —— 4 重建二叉树
描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int pre_len = pre.size();
		int vin_len = vin.size();

		if (pre_len == 0 || vin_len == 0 || pre_len != vin_len) return NULL;

		TreeNode *head = new TreeNode(pre[0]);
		int root_id = 0;
		for (int i = 0; i < vin_len; i++)
		{
			if (vin[i] == pre[0]) {
				root_id = i;
				break;
			}
		}

		vector<int> pre_left, pre_right, in_left, in_right;
		for (int j = 0; j < root_id; j++)
		{
			in_left.push_back(vin[j]);
			pre_left.push_back(pre[j + 1]);
		}
		for (int j = root_id + 1; j < vin_len; j++)
		{
			in_right.push_back(vin[j]);
			pre_right.push_back(pre[j]);
		}
		head->left = reConstructBinaryTree(pre_left, in_left);
		head->right = reConstructBinaryTree(pre_right, in_right);
		return head;
	}
};