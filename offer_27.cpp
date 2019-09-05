/*��ָoffer ���� 27 �ַ���������
����������һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str != "") dfs(str, 0);
		sort(ret.begin(), ret.end());
		return ret;
	}
private:
	vector<string> ret;
	void dfs(string str, int s) {
		int sz = str.size();
		if (s == sz) {
			ret.push_back(str);
			return;
		}
		for (int i = s; i < sz; ++i) {
			if (i != s && str[s] == str[i]) continue;
			swap(str[s], str[i]);
			dfs(str, s + 1);
		}
	}
};