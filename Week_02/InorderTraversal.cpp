#include <vector>
#include <stack>

/*���������������
* �ⷨ
* 1���ݹ顪��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��
* 2����������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O��n�������Ҹо������õ�ʱ�����Ƿ�ֹ�ݹ�̫����ɶ�ջ����������õݹ�ͺã����׶�
* 2.1��ջ
*/
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> st;
	if (root == nullptr) return result;
	while (!st.empty() || root) {//ע��������ڵ�ķ���ʱ�����ж������Ѿ����д����
		//�����������ӽڵ�
		while (root) {
			st.push(root);
			root = root->left;
		}
		//���ӽڵ�ֵ
		root = st.top();
		st.pop();
		result.push_back(root->val);
		root = root->right;
	}
	return result;
}

