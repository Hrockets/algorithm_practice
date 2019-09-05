/*剑指offer —— 27 字符串的排列
描述：输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
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