#include <vector>

/*******移动零
* 双指针
*/


void moveZeroes(std::vector<int>& nums) {
    //双指针，一个指针记录0位置，一个用来遍历
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            std::swap(nums[j++], nums[i]);
        }
    }
}