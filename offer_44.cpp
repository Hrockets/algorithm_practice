/*剑指offer —— 44 翻转单词顺序列
描述：
例如，“student. a am I”。正确的句子应该是“I am a student.”。
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