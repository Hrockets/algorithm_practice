/*��ָoffer ���� 4 �ؽ�������
����������ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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