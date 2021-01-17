#include <unordered_map>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

 /*
 �Լ��ֶ����Ի����������Ǵ���û˼·
 */

unordered_map<int, int> mapIn;
//nL:��߽磬nR���ұ߽磬nPreIndex��ǰ�����������
TreeNode* rebuildTree(vector<int>& preorder, vector<int>& inorder, int nL, int nR, int& nPreIndex) {
    //����nPreIndexд���ˣ����н�����һ�飬����һ��Ҫ��ַ���ݣ�������ֵ���ݡ�����ÿһ��ѭ�������󻹻����±�����
    if (nL > nR || nPreIndex >= preorder.size()) return nullptr;

    int value = preorder[nPreIndex];
    TreeNode* pNode = new TreeNode(value);
    nPreIndex++;
    int nInIndex = mapIn[value];

    pNode->left = rebuildTree(preorder, inorder, nL, nInIndex - 1, nPreIndex);
    //����nR�߽�д���ˣ�����дpreorder.size()�������ұ߽���ظ�����
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