#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

/*  ��ĸ��λ��
* ��ϣ����ʱ�ո��Ӷ�O��nklogk������nΪ�ַ�����Ŀ��kΪ�ַ�����󳤶�
* �����򣬴浽��ϣ����
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