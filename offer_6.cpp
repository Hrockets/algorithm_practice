/*剑指offer —— 6 旋转数组的最小数字
描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int index1 = 0;
		int index2 = rotateArray.size() - 1;
		int Midindex = index1;//可能未旋转，直接返回首元素
		while (rotateArray[index1] >= rotateArray[index2])
		{
			if (index2 - index1 == 1)//循环出口
			{
				Midindex = index2;
				break;
			}
			Midindex = (index1 + index2) / 2;
			//特殊情况：如果无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
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
			//中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
			if (rotateArray[index1] <= rotateArray[Midindex])
				index1 = Midindex;
			else if (rotateArray[Midindex] <= rotateArray[index2])
				index2 = Midindex;
		}
		return rotateArray[Midindex];
	}
};
