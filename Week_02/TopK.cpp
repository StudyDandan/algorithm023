#include <vector>
#include <queue>
#include <unordered_map>

/*最高频率的K个数
* 优先队列——时间复杂度O（nlog（k））
*/

using namespace std;
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second < n.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    if (nums.size() < k) return result;
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) hashmap[nums[i]]++;

    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(&cmp)> pq(cmp);
    auto ito = hashmap.begin();
    while (ito != hashmap.end()) {
        //这里可以做一些优化
        if (pq.size() == k) {
            if (pq.top().second < ito->second) {
                pq.pop();
                pq.emplace(ito->first, ito->second);
            }
        }
        else {
            pq.push(std::make_pair(ito->first, ito->second));
        }
        ito++;
    }

    for (int i = 0; i < k; i++) {
        if (pq.size() == 0) break;
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int> nums = { 1,1,1,2,2,3 };
    int k = 2;
    topKFrequent(nums, k);
}