/*��ָoffer ���� 52 ������ʽƥ��
��������ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		// ָ��Ϊ�գ�����false
		if (str == NULL || pattern == NULL) {
			return false;
		}
		return matchCore(str, pattern);
	}
private:
	bool matchCore(char* str, char* pattern) {
		// �ַ�����ģʽ�������е��˽�β������true
		if (*str == '\0' && *pattern == '\0') {
			return true;
		}
		// �ַ���û�е���β��ģʽ�����ˣ��򷵻�false
		// ģʽ��û�е���β���ַ������ˣ�����ݺ����жϽ��У���Ҫ��'*'������
		if ((*str != '\0' && *pattern == '\0')) {
			return false;
		}
		// ���ģʽ������һ���ַ���'*'�������״̬����ƥ��
		if (*(pattern + 1) == '*') {
			// ����ַ�����ģʽ����ȣ�����ģʽ����'.'�������ַ���û�е���β�������ƥ��
			if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
				// ������һ��״̬������ƥ�䵽��һ��
				return matchCore(str + 1, pattern + 2) ||
					// ���ֵ�ǰ״̬�����Ǽ��������'*'ȥƥ��
					matchCore(str + 1, pattern) ||
					// �������'*'
					matchCore(str, pattern + 2);
			}
			// ����ַ�����ģʽ������ȣ���������ǰģʽ�����ַ���'*'��������һ�ֵ�ƥ��
			else {
				// �������'*'
				return matchCore(str, pattern + 2);
			}
		}
		// ����ַ�����ģʽ����ȣ�����ģʽ����'.'�������ַ���û�е���β�������ƥ��
		if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
			return matchCore(str + 1, pattern + 1);
		}
		return false;
	}
};


