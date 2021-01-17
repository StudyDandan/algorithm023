#include <vector>
/*回溯法
还是要再练习
时间复杂度O（n*n!），空间复杂度O（n）*/

using namespace std;
vector<vector<int>> result;
void dfs(int cur, vector<int>& nums) {
    if (cur == (nums.size() - 1)) {
        result.push_back(nums);
        return;
    }

    for (int i = cur; i < nums.size(); ++i) {//注意这里是++i，这样就不用再写单独判断的函数了
        swap(nums[cur], nums[i]);
        dfs(cur + 1, nums);
        swap(nums[i], nums[cur]);//回溯法一定要把状态回置
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    result.clear();
    dfs(0, nums);
    return result;
}