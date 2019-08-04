//leetcode 41 缺失的第一个正整数
/*给定一个未排序的整数数组，找出其中没有出现的最小的正整数 1。*/
int firstMissingPositive(vector<int>& nums) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	//排序后数组没有正整数
	if (len == 0 || nums[len - 1] <= 0) return 1;

	int target = 1;
	for (int i = 0; i < len; i++) {
		if (nums[i] == target) target++;
	}
	return target;
}