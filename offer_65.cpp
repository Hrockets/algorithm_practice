/*��ָoffer ���� 65 �����е�·��
�����������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ�
���� 
a b c e 
s f c s 
a d e e �����а���һ���ַ���"bccced"��·������
�Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*/

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) {
			return false;
		}
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		int pathLength = 0;
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
					delete[] visited;
					return true;
				}
			}
		}
		delete[] visited;
		return false;
	}
private:
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited) {
		if (str[pathLength] == '\0') {
			return true;
		}
		bool hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]) {
			++pathLength;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
			if (!hasPath) {
				--pathLength;
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
};