#include <vector>
/*���ݷ�
����Ҫ����ϰ
ʱ�临�Ӷ�O��n*n!�����ռ临�Ӷ�O��n��*/

using namespace std;
vector<vector<int>> result;
void dfs(int cur, vector<int>& nums) {
    if (cur == (nums.size() - 1)) {
        result.push_back(nums);
        return;
    }

    for (int i = cur; i < nums.size(); ++i) {//ע��������++i�������Ͳ�����д�����жϵĺ�����
        swap(nums[cur], nums[i]);
        dfs(cur + 1, nums);
        swap(nums[i], nums[cur]);//���ݷ�һ��Ҫ��״̬����
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    result.clear();
    dfs(0, nums);
    return result;
}