#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

/*  字母异位词
* 哈希表——时空复杂度O（nklogk）——n为字符串数目，k为字符串最大长度
* 先排序，存到哈希表中
*/

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> result;
	unordered_map<string, vector<string>> mapGroup;
	for (int i = 0; i < strs.size(); i++) {
		string str = strs[i];
		sort(str.begin(), str.end());
		mapGroup[str].push_back(strs[i]);
	}

	auto ito = mapGroup.begin();
	while (ito != mapGroup.end()){
		result.push_back(ito->second);
		ito++;
	}

	return result;
}