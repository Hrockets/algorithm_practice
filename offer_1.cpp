/*��ָoffer ���� 1 ��ά�����еĲ���
��������һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = (int)array.size();//��
		int col = (int)array[0].size();//��
		if (row == 0 || col == 0) return false;
		//���Ͻ���С�����½����
		if (target<array[0][0] || target>array[row - 1][col - 1])
			return false;
		//ѡȡ���Ͻǵ���
		int i = 0;
		int j = col - 1;
		while (i < row&&j >= 0)
		{
			if (target > array[i][j]) i++;//��һ��
			else if (target < array[i][j]) j--;//ǰһ��
			else return 1;
		}
		return 0;
	}
};