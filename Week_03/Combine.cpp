#include <vector>
/*
解法：递归
优化的地方：尽量减少值拷贝，否则内存消耗大，性能也慢。
*/
using namespace std;

vector<int> single;
vector<vector<int>> result;
void traverse(int i, int n, int k) {
    if (single.size() == k) {
        result.push_back(single);
        return;
    }
    if ((k - single.size()) > (n - i + 1)) return;//较少无用的判断，否则超出时间限制

    traverse(i + 1, n, k);
    single.push_back(i);
    traverse(i + 1, n, k);
    single.pop_back();//single做成全局变量，如果作为参数传递，会产生值传递，性能慢，内存高
}

vector<vector<int>> combine(int n, int k) {
    traverse(1, n, k);
    return result;
}

void main()
{
    combine(20, 16);
}