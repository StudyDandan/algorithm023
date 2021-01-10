#include <vector>
#include <stack>

/*二叉树的中序遍历
* 解法
* 1、递归——时间复杂度O（n），空间复杂度O（1）
* 2、迭代——时间复杂度O(n)，空间复杂度O（n）——我感觉迭代用的时机就是防止递归太深造成堆栈溢出，否则用递归就好，简单易懂
* 2.1、栈
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
	while (!st.empty() || root) {//注意这个根节点的放入时机，判断条件已经多次写错了
		//遍历所有左子节点
		while (root) {
			st.push(root);
			root = root->left;
		}
		//左子节点值
		root = st.top();
		st.pop();
		result.push_back(root->val);
		root = root->right;
	}
	return result;
}

