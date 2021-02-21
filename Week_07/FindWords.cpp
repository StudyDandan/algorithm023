#include <vector>
#include <iostream>

using namespace std;

/*
* 实现思路
* 1、将待查单词放置到字典树中
* 2、挨个遍历board中的字母
* 3、每个字母用回溯法判断单词是否有效（注意trie指针，恢复状态）
* 4、判断中，有效的word记录之后置空，防止重复
* 5、每个字符遍历之后用@字符替换，防止来回查找，结束后恢复
* 6、老师说的上下左右查找换成数组方式还没试
* 7、注意：查找到一个单词后不能return返回，还要接着往下找，否则有些情况找不全
*/
struct Trie {
    string word;
    Trie* next[26];
};

vector<string> result;

size_t nRow = 0;
size_t nCol = 0;

//回溯法
void dfs(size_t row, size_t col, Trie* root, vector<vector<char>>& board) {
    size_t index = board[row][col] - 'a';
    if (board[row][col] == '@' || root->next[index] == nullptr) return;
    root = root->next[index];
    if (root->word != "") {
        result.push_back(root->word);
        root->word = "";//防止重复单词
        //return;这句话要注释掉，否则对于oath、oathf、oathfk这种，只能查出最短的
    }

    //临时修改访问过的元素，防止重复访问，如果用visited呢？
    char ch = board[row][col];
    board[row][col] = '@';
    if (row < nRow - 1) dfs(row + 1, col, root, board);
    if (row > 0) dfs(row - 1, col, root, board);
    if (col < nCol - 1) dfs(row, col + 1, root, board);
    if (col > 0) dfs(row, col - 1, root, board);
    board[row][col] = ch;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    //把words放入trie中，时间复杂度O（n*m）

    nRow = board.size();
    nCol = nRow ? board[0].size() : 0;
    Trie* node = new Trie();
    Trie* root = node;
    for (int i = 0; i < words.size(); ++i) {
        node = root;//要记得还原node节点
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

    //遍历m*n个单词，看看是否能查到
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