//leetcode 1 ����֮��
/*���α��� һ�δ洢��һ�β���*/
vector<int> twoSum(vector<int>& nums, int target) {
	map<int,int> m;
	vector<int> v;
	for(int i=0;i<nums.size();i++)
		m[nums[i]]=i;
	for(int i=0;i<nums.size();i++)
	{
		auto it=m.find(target-nums[i]);
		if(it!=m.end()&&it->second!=i)
		{
			v.push_back(i);
			v.push_back(it->second);
			break;
		}
	}
	return v;
}


