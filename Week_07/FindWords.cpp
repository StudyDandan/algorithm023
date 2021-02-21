#include <vector>
#include <iostream>

using namespace std;

/*
* ʵ��˼·
* 1�������鵥�ʷ��õ��ֵ�����
* 2����������board�е���ĸ
* 3��ÿ����ĸ�û��ݷ��жϵ����Ƿ���Ч��ע��trieָ�룬�ָ�״̬��
* 4���ж��У���Ч��word��¼֮���ÿգ���ֹ�ظ�
* 5��ÿ���ַ�����֮����@�ַ��滻����ֹ���ز��ң�������ָ�
* 6����ʦ˵���������Ҳ��һ������鷽ʽ��û��
* 7��ע�⣺���ҵ�һ�����ʺ���return���أ���Ҫ���������ң�������Щ����Ҳ�ȫ
*/
struct Trie {
    string word;
    Trie* next[26];
};

vector<string> result;

size_t nRow = 0;
size_t nCol = 0;

//���ݷ�
void dfs(size_t row, size_t col, Trie* root, vector<vector<char>>& board) {
    size_t index = board[row][col] - 'a';
    if (board[row][col] == '@' || root->next[index] == nullptr) return;
    root = root->next[index];
    if (root->word != "") {
        result.push_back(root->word);
        root->word = "";//��ֹ�ظ�����
        //return;��仰Ҫע�͵����������oath��oathf��oathfk���֣�ֻ�ܲ����̵�
    }

    //��ʱ�޸ķ��ʹ���Ԫ�أ���ֹ�ظ����ʣ������visited�أ�
    char ch = board[row][col];
    board[row][col] = '@';
    if (row < nRow - 1) dfs(row + 1, col, root, board);
    if (row > 0) dfs(row - 1, col, root, board);
    if (col < nCol - 1) dfs(row, col + 1, root, board);
    if (col > 0) dfs(row, col - 1, root, board);
    board[row][col] = ch;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    //��words����trie�У�ʱ�临�Ӷ�O��n*m��

    nRow = board.size();
    nCol = nRow ? board[0].size() : 0;
    Trie* node = new Trie();
    Trie* root = node;
    for (int i = 0; i < words.size(); ++i) {
        node = root;//Ҫ�ǵû�ԭnode�ڵ�
        for (auto ch : words[i]) {
            size_t index = ch - 'a';
            if (node->next[index] == nullptr) {
                Trie* child = new Trie();
                node->next[index] = child;
            }
            node = node->next[index];
        }
        node->word = words[i];
    }

    //����m*n�����ʣ������Ƿ��ܲ鵽
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            dfs(row, col, root, board);
        }
    }
    return result;
}

void main() {

    vector<vector<char>> board = { {'o', 'a', 'a', 'n'} ,{'e', 't', 'a', 'e'},{'i', 'h', 'k', 'r'},{'i', 'f', 'l', 'v'} };
    vector<string> words = { "oath", "pea", "eat", "rain", "hklf", "hf" };
    
    findWords(board,words);
}