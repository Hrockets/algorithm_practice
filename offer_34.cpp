/*��ָoffer ���� 34 ��һ��ֻ����һ�ε��ַ�
��������һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)
���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
*/

class Solution {
public:
	int FirstNotRepeatingChar(string str) {

		map<char, int> mp;
		for (int i = 0; i < str.size(); ++i)
			mp[str[i]]++;
		for (int i = 0; i < str.size(); ++i) {
			if (mp[str[i]] == 1)
				return i;
		}
		return -1;
	}
};