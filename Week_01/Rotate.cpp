#include <vector>
//��ת����

/*�ⷨ��
* 1���½����飬����������ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1������������Ҫ��Ҫ��ԭ�ط�ת
* 2�������ⷨ
* 3���ֶη�ת��ʱ�临�Ӷ�O��n��
* 4���������ӡ���û����
*/

void rotate(std::vector<int>& nums, int k) {
    if (nums.size() < k) k %= nums.size();//�տ�ʼû�п����������
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