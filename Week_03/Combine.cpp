#include <vector>
/*
�ⷨ���ݹ�
�Ż��ĵط�����������ֵ�����������ڴ����Ĵ�����Ҳ����
*/
using namespace std;

vector<int> single;
vector<vector<int>> result;
void traverse(int i, int n, int k) {
    if (single.size() == k) {
        result.push_back(single);
        return;
    }
    if ((k - single.size()) > (n - i + 1)) return;//�������õ��жϣ����򳬳�ʱ������

    traverse(i + 1, n, k);
    single.push_back(i);
    traverse(i + 1, n, k);
    single.pop_back();//single����ȫ�ֱ����������Ϊ�������ݣ������ֵ���ݣ����������ڴ��
}

vector<vector<int>> combine(int n, int k) {
    traverse(1, n, k);
    return result;
}

void main()
{
    combine(20, 16);
}