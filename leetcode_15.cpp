//leetcode 15 三数之和
/*给定一个包含 n 个整数的数组?nums，判断?nums?中是否存在三个元素 a，b，c ，
使得?a + b + c = 0 ？找出所有满足条件且不重复的三元组。
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if(nums.size() < 3) return res;
	sort(nums.begin(), nums.end());
	int l = 0;
	int r = 0;
	int sum = 0;
	for(int i = 0; i < nums.size() - 2; i++)
	{
		if(nums[i] > 0) break;
		if(i > 0 && nums[i] == nums[i - 1]) continue;//去重
		l = i + 1;
		r = nums.size() - 1;
		while(l < r)
		{
			sum = nums[i] + nums[l] + nums[r];
			if(sum == 0)
			{
				res.push_back({nums[i], nums[l], nums[r]});
				l++;
				r--;
				while(l < r && nums[l] == nums[l - 1]) l++;//去重
				while(l < r && nums[r] == nums[r + 1]) r--;//去重
			}
			else if(sum < 0) l++;
			else  r--;
		}
		
	}
	return res;
}
