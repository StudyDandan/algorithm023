#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //����BFS
    unordered_set<string> bank, visited;//��set���ٲ���
    for (int i = 0; i < wordList.size(); i++) {
        bank.insert(wordList[i]);
    }
    if (bank.find(endWord) == bank.end())return 0;

    queue<string> recordBegin;
    recordBegin.push(beginWord);
    int nSize = 0;
    int level = 1;//��Ŀ��˼��������
    string strTmp;
    while (!recordBegin.empty()) {
        nSize = recordBegin.size();
        while (nSize--) {
            strTmp = recordBegin.front();
            recordBegin.pop();
            for (int j = 0; j < strTmp.size(); j++) {
                char ch = strTmp[j];
                for (int i = 0; i < 26; i++) {//ֱ����ĸ�滻
                    char chNew = i + 'a';
                    if (strTmp[j] == chNew) continue;
                    strTmp[j] = chNew;
                    if (strTmp == endWord) return ++level;
                    if (bank.find(strTmp) != bank.end()) {
                        recordBegin.push(strTmp);
                        bank.erase(strTmp);
                    }
                }
                strTmp[j] = ch;
            }
        }
        ++level;
    }
    return 0;
}

//void main()
//{
//    vector<string> bank = { "hot", "dot", "dog", "lot", "log"};
//    ladderLength("hit", "cog", bank);
//}