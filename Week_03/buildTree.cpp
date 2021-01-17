#include <unordered_map>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

 /*
 自己手动可以画出来，但是代码没思路
 */

unordered_map<int, int> mapIn;
//nL:左边界，nR：右边界，nPreIndex：前序遍历的索引
TreeNode* rebuildTree(vector<int>& preorder, vector<int>& inorder, int nL, int nR, int& nPreIndex) {
    //这里nPreIndex写错了，所有结点遍历一遍，这里一定要是址传递，不能是值传递。否则每一层循环结束后还会重新遍历。
    if (nL > nR || nPreIndex >= preorder.size()) return nullptr;

    int value = preorder[nPreIndex];
    TreeNode* pNode = new TreeNode(value);
    nPreIndex++;
    int nInIndex = mapIn[value];

    pNode->left = rebuildTree(preorder, inorder, nL, nInIndex - 1, nPreIndex);
    //这里nR边界写错了，不能写preorder.size()。否则右边界会重复遍历
    pNode->right = rebuildTree(preorder, inorder, nInIndex + 1, nR, nPreIndex);
    return pNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
        mapIn[inorder[i]] = i;
    }
    int nPreIndex = 0;
    return rebuildTree(preorder, inorder, 0, inorder.size() - 1, nPreIndex);
}

//void main()
//{
//    vector<int> preorder = { 3,9,20,15,7 };
//    vector<int> inorder = { 9,3,15,20,7 };
//    buildTree(preorder, inorder);
//}