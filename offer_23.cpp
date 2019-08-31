/*剑指offer —— 23 二叉搜索树的后序遍历序列
描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0) return false;
		if (sequence.size() == 1) return true;
		return bfs(sequence, 0, sequence.size() - 1);
	}
	bool bfs(vector<int> v, int start, int end)
	{
		if (start >= end) return true;
		int i = start;
		while (v[i] < v[end]) {
			i++;
		}
		for (int j = i; j < end; j++) {
			if (v[j] < v[end])
				return false;
		}
		return bfs(v, start, i - 1) && bfs(v, i, end - 1);//左子树 右子树 根节点不要
	}
};