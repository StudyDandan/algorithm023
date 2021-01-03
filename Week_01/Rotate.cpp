#include <vector>
//旋转数组

/*解法：
* 1、新建数组，挨个遍历，时间复杂度O（n），空间复杂度O（1）——不满足要求，要求原地翻转
* 2、暴力解法
* 3、分段反转，时间复杂度O（n）
* 4、环形链接——没看懂
*/

void rotate(std::vector<int>& nums, int k) {
    if (nums.size() < k) k %= nums.size();//刚开始没有考虑这种情况
    std::reverse(nums.begin(), nums.end());
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

void reverse(std::vector<int>& nums, int nStart, int nEnd) {
    int j = nEnd;
    for (int i = nStart; i <= j; i++) {
        std::swap(nums[i], nums[j--]);
    }
}