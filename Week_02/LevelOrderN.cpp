#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*N叉树层序遍历
1、队列——时间复杂度O（n），空间复杂度O（n）
1.1、队列的值：que(1)/pop(1),que()/que(3,2,4)/pop(3),que(2,4)/que(2,4,5,6)/pop(2),que(4,5,6)/pop(4),que(5,6)/pop(5),que(6)/pop(6),que()
2、广度优先遍历——待做
3、深度优先遍历——待做
*/
vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> que;
    vector<vector<int>> result;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> levelResult;
        for (int i = 0; i < size; i++) {//注意size不能写成que.size（），因为que一直在变
            Node* p = que.front();
            que.pop();
            levelResult.push_back(p->val);
            for (int j = 0; j < p->children.size(); j++) {
                que.push(p->children[j]);
            }
        }
        result.push_back(levelResult);
    }
    return result;
}

int main()
{
    //1, null, 3, 2, 4, null, 5, 6
    Node* c11 = new Node(5);
    Node* c12 = new Node(6);
    vector<Node*> vecNode = { c11, c12 };

    Node* c1 = new Node(3, vecNode);
    Node* c2 = new Node(2);
    Node* c3 = new Node(4);

    vector<Node*> vecNodeRoot = { c1,c2,c3 };
    Node* root = new Node(1, vecNodeRoot);
    //preorder(root);
    levelOrder(root);
}