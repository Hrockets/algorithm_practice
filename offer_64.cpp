/*剑指offer —— 64 滑动窗口的最大值
描述：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， 
{2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， 
{2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。*/

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> vec;
		if (num.size() == 0 || num.size() < size || size == 0) return vec;

		deque<int> dq;
		//处理前size个数据，因为这个时候不需要输出最大值；
		for (unsigned int i = 0; i < size; i++)
		{
			//假如当前的元素比队列队尾的元素大，说明之前加入的这些元素不可能是最大值了。因为当前的这个数字比之前加入队列的更晚
			while (!dq.empty() && num[i] >= num[dq.back()])
				dq.pop_back();//弹出比当前小的元素下标
			dq.push_back(i);//队尾压入当前下标
		}
		//处理size往后的元素，这时候需要输出滑动窗口的最大值
		for (unsigned int i = size; i < num.size(); i++)
		{
			vec.push_back(num[dq.front()]);
			while (!dq.empty() && num[i] >= num[dq.back()])
				dq.pop_back();
			if (!dq.empty() && dq.front() <= (int)(i - size))//判断队头的下标是否超出size大小，如果超过，要删除队头元素
				dq.pop_front();//删除队头元素
			dq.push_back(i);//将当前下标压入队尾，因为可能在未来是最大值
		}
		vec.push_back(num[dq.front()]);//最后还要压入一次
		return vec;
	}
};