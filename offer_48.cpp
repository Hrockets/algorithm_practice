/*��ָoffer ���� 48 ���üӼ��˳��ļӷ�
������дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*/

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0) {
			int sum = num1 ^ num2;//�����λ�����
			int carray = (num1 & num2) << 1;//�����λ
			num1 = sum;
			num2 = carray;
		}
		return num1;
		//if(num1>0){
			//while(num1--!=0)
				//num2++;
		//}
		//else if(num1<0){
			//while(num1++!=0)
				//num2--;
		//}
		//return num2;
	}
};


