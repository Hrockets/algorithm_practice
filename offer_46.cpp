/*剑指offer —— 46 孩子们的游戏（圆圈中最后剩下的数）
描述：每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中
,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
如果没有小朋友，请返回-1
*/

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1) {
			return -1;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++) v[i] = i;
		int out_cnt = 0, cnt = n, cur_index = 0;
		while (out_cnt < n - 1) {
			if (cur_index + m > cnt) {
				if ((cur_index + m) % cnt == 0)
					cur_index = cnt - 1;
				else cur_index = (cur_index + m) % cnt - 1;
			}
			else
				cur_index = cur_index + m - 1;
			out_cnt++; cnt--;
			cout << *(v.begin() + cur_index) << endl;
			v.erase(v.begin() + cur_index);
		}
		return v[0];
	}
};

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		// invalid input
		if (n <= 0 || m < 0)
			return -1;

		// if there are only one integer in the circle initially,
		// of course the last remaining one is 0
		int lastinteger = 0;

		// find the last remaining one in the circle with n integers
		for (int i = 2; i <= n; i++)
			lastinteger = (lastinteger + m) % i;

		return lastinteger;
	}
};