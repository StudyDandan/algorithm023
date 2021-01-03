#include <vector>

/*********删除排序数组中的重复项
* 
* 解法：双指针，时间复杂度O（n），空间复杂度O（1）
* 第一遍做时，知道用双指针，但是判断出重复元素之后不知道如何去重，还整了个嵌套循环。。。
*/

int removeDuplicates(std::vector<int>& nums)
{
	if (nums.size() <= 1) return nums.size();

	int j = 0;
	for (int i = 1; i < nums.size(); i++){
		if (nums[i] != nums[j]) {
			nums[++j] = nums[i];//直接覆盖掉就好了，就相当于统一后移了，不需要交换元素
		}
	}
	return j + 1;
}