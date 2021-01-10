#include <vector>
#include <stack>
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

/*������ǰ�����
* �ⷨ��
* 1���ݹ顪��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1������������ռ�ÿռ䲻����
* 2����������ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��n��
*/
vector<int> preorder(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;
    //traverse(root, result);

    //������ 
    stack<Node*> st;
    st.push(root);
    int childSize = 0;
    while (!st.empty()) {
        root = st.top();
        if (root == nullptr) continue;
        st.pop();
        result.push_back(root->val);
        childSize = root->children.size();
        if(childSize == 0) continue;
        for(int i = childSize - 1; i >= 0; i--){
            if(root->children[i]) st.push(root->children[i]);
        }
        root = root->children[0];
    }
    return result;
}

int main()
{
    //1, null, 3, 2, 4, null, 5, 6
    Node* c11 = new Node(5);
    Node* c12 = new Node(6);
    vector<Node*> vecNode = {c11, c12};

    Node* c1 = new Node(3,vecNode);
    Node* c2 = new Node(2);
    Node* c3 = new Node(4);

    vector<Node*> vecNodeRoot = {c1,c2,c3};
    Node* root = new Node(1, vecNodeRoot);
    preorder(root);
}