/*��ָoffer ���� 6 ��ת�������С����
��������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int index1 = 0;
		int index2 = rotateArray.size() - 1;
		int Midindex = index1;//����δ��ת��ֱ�ӷ�����Ԫ��
		while (rotateArray[index1] >= rotateArray[index2])
		{
			if (index2 - index1 == 1)
			{
				Midindex = index2;
				break;
			}
			Midindex = (index1 + index2) / 2;
			//�������������޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ��������飬ֻ��˳�����
			if (rotateArray[index1] == rotateArray[index2] &&
				rotateArray[Midindex] == rotateArray[index1])
			{
				int result = rotateArray[index1];
				for (int i = index1 + 1; i < rotateArray.size(); i++)
				{
					if (rotateArray[i] < result)
						result = rotateArray[i];
				}
				return result;
			}
			//�м�Ԫ��λ��ǰ��ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[index1] <= rotateArray[Midindex])
				index1 = Midindex;
			else if (rotateArray[Midindex] <= rotateArray[index2])
				index2 = Midindex;
		}
		return rotateArray[Midindex];
	}
};
