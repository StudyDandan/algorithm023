#include <vector>

/*********ɾ�����������е��ظ���
* 
* �ⷨ��˫ָ�룬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��
* ��һ����ʱ��֪����˫ָ�룬�����жϳ��ظ�Ԫ��֮��֪�����ȥ�أ������˸�Ƕ��ѭ��������
*/

int removeDuplicates(std::vector<int>& nums)
{
	if (nums.size() <= 1) return nums.size();

	int j = 0;
	for (int i = 1; i < nums.size(); i++){
		if (nums[i] != nums[j]) {
			nums[++j] = nums[i];//ֱ�Ӹ��ǵ��ͺ��ˣ����൱��ͳһ�����ˣ�����Ҫ����Ԫ��
		}
	}
	return j + 1;
}