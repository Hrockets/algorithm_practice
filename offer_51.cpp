/*��ָoffer ���� 51 �����˻�����
����������һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
*/

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int n = A.size();
		vector<int> b(n);
		int ret = 1;
		for (int i = 0; i < n; ret *= A[i++]) {
			b[i] = ret;
		}
		ret = 1;
		for (int i = n - 1; i >= 0; ret *= A[i--]) {
			b[i] *= ret;
		}
		return b;
	}
};


