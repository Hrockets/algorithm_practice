/*��ָoffer ���� 32 �������ų���С����
����������һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}��
���ӡ���������������ųɵ���С����Ϊ321323��
*/

/*��vector�����ڵ����ݽ������򣬰��� ��a��bתΪstring��
 �� a��b<b+a  a������ǰ �Ĺ�������,
 �� 2 21 ��Ϊ 212 < 221 ���� �����Ϊ 21 2
  to_string() ���Խ�int ת��Ϊstring
*/ class Solution {
public:
	static bool cmp(int a, int b) {
		string A = "";
		string B = "";
		A += to_string(a);
		A += to_string(b);
		B += to_string(b);
		B += to_string(a);

		return A < B;
	}
	string PrintMinNumber(vector<int> numbers) {
		string  answer = "";
		sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i < numbers.size(); i++) {
			answer += to_string(numbers[i]);
		}
		return answer;
	}
 };