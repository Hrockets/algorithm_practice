/*��ָoffer ���� 13 ��������˳��ʹ����λ��ż��ǰ��
����������һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
*/

/*�������Ŀռ��ԭ�����������ȷ��������ڷ�ż��*/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> res;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 1)
				res.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
				res.push_back(array[i]);
		}
		array = res;
	}
};


/*ԭ������ ���ò���˼�� ��¼������ǰ��λ��*/
void reOrderArray(vector<int> &array) {
	//���λ�ò��䣬�ȶ���
	//���������˼��
	int m = array.size();
	int k = 0;//��¼�Ѿ��ں�λ�õ������ĸ���
	for (int i = 0; i < m; i++) {
		if (array[i] % 2 == 1) {
			int j = i;
			while (j > k) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				j--;
			}
			k++;
		}
	}
}