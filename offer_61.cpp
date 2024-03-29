/*剑指offer —— 61 序列化二叉树
描述：请实现两个函数，分别用来序列化和反序列化二叉树。*/

class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (!root) {
			return NULL;
		}
		string str;
		SerializeCore(root, str);
		// 把str流中转换为字符串返回
		int length = str.length();
		char* res = new char[length + 1];
		// 把str流中转换为字符串返回
		for (int i = 0; i < length; i++) {
			res[i] = str[i];
		}
		res[length] = '\0';
		return res;
	}
	TreeNode* Deserialize(char *str) {
		if (!str) {
			return NULL;
		}
		TreeNode* res = DeserializeCore(&str);
		return res;
	}
	void SerializeCore(TreeNode* root, string& str) {
		// 如果指针为空，表示左子节点或右子节点为空，则在序列中用#表示
		if (!root) {
			str += '#';
			return;
		}
		string tmp = to_string(root->val);
		str += tmp;
		// 加逗号，用于区分每个结点
		str += ',';
		SerializeCore(root->left, str);
		SerializeCore(root->right, str);
	}
	// 递归时改变了str值使其指向后面的序列，因此要声明为char**
	TreeNode* DeserializeCore(char** str) {
		// 到达叶节点时，调用两次，都返回null，所以构建完毕，返回父节点的构建
		if (**str == '#') {
			(*str)++;
			return NULL;
		}
		// 因为整数是用字符串表示，一个字符表示一位，先进行转换
		int num = 0;
		while (**str != ',' && **str != '\0') {
			num = num * 10 + ((**str) - '0');
			(*str)++;
		}
		TreeNode* root = new TreeNode(num);
		if (**str == '\0') {
			return root;
		}
		else {
			(*str)++;
		}
		root->left = DeserializeCore(str);
		root->right = DeserializeCore(str);
		return root;
	}
};