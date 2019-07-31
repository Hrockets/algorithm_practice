/*��ָoffer ���� 64 �������ڵ����ֵ
����������һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� 
�������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� 
{2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� 
{2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��*/

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> vec;
		if (num.size() == 0 || num.size() < size || size == 0) return vec;

		deque<int> dq;
		//����ǰsize�����ݣ���Ϊ���ʱ����Ҫ������ֵ��
		for (unsigned int i = 0; i < size; i++)
		{
			//���統ǰ��Ԫ�رȶ��ж�β��Ԫ�ش�˵��֮ǰ�������ЩԪ�ز����������ֵ�ˡ���Ϊ��ǰ��������ֱ�֮ǰ������еĸ���
			while (!dq.empty() && num[i] >= num[dq.back()])
				dq.pop_back();//�����ȵ�ǰС��Ԫ���±�
			dq.push_back(i);//��βѹ�뵱ǰ�±�
		}
		//����size�����Ԫ�أ���ʱ����Ҫ����������ڵ����ֵ
		for (unsigned int i = size; i < num.size(); i++)
		{
			vec.push_back(num[dq.front()]);
			while (!dq.empty() && num[i] >= num[dq.back()])
				dq.pop_back();
			if (!dq.empty() && dq.front() <= (int)(i - size))//�ж϶�ͷ���±��Ƿ񳬳�size��С�����������Ҫɾ����ͷԪ��
				dq.pop_front();//ɾ����ͷԪ��
			dq.push_back(i);//����ǰ�±�ѹ���β����Ϊ������δ�������ֵ
		}
		vec.push_back(num[dq.front()]);//���Ҫѹ��һ��
		return vec;
	}
};