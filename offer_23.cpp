/*��ָoffer ���� 23 �����������ĺ����������
����������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
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
		return bfs(v, start, i - 1) && bfs(v, i, end - 1);//������ ������ ���ڵ㲻Ҫ
	}
};