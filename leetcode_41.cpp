//leetcode 41 ȱʧ�ĵ�һ��������
/*����һ��δ������������飬�ҳ�����û�г��ֵ���С�������� 1��*/
int firstMissingPositive(vector<int>& nums) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	//���������û��������
	if (len == 0 || nums[len - 1] <= 0) return 1;

	int target = 1;
	for (int i = 0; i < len; i++) {
		if (nums[i] == target) target++;
	}
	return target;
}