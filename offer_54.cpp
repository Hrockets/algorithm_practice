/*��ָoffer ���� 54 �ַ����е�һ�����ظ����ַ�
��������ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
*/

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		s += ch;
		count[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (int i = 0; i < s.size(); i++) {
			if (count[s[i]] == 1)
			{
				return s[i];
			}
		}
		return '#';
	}
private:
	string s;
	int count[256] = { 0 };
};