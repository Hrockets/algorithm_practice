/*��ָoffer ���� 44 ��ת����˳����
������
���磬��student. a am I������ȷ�ľ���Ӧ���ǡ�I am a student.����
*/
class Solution {
public:
	string ReverseSentence(string str) {

		string res = "", tmp = "";
		for(unsigned int i = 0; i < str.size(); ++i){
			if(str[i] == ' ') res = " " + tmp + res, tmp = "";
			else tmp += str[i];
		}
		if(tmp.size()) res = tmp + res;
		return res;
	}
};