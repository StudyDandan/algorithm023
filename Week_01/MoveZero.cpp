#include <vector>

/*******�ƶ���
* ˫ָ��
*/


void moveZeroes(std::vector<int>& nums) {
    //˫ָ�룬һ��ָ���¼0λ�ã�һ����������
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            std::swap(nums[j++], nums[i]);
        }
    }
}