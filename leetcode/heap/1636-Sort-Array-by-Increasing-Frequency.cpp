
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * 根据元素出现的频次降续排序，若频次相同，则按照原有大小降序排序
 * 
 * 和频次相关的最直接的就是使用 hashmap 进行统计，然后排序输出。
 */
class Solution {
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> frequency;
        for (int i = 0; i < nums.size(); i++)
            frequency[nums[i]] ++;
        
        vector<pair<int, int>> auxiliary;
        for (auto item : frequency)
            auxiliary.push_back(item);
        
        sort(auxiliary.begin(), auxiliary.end(), cmp);

        vector<int> result;
        for (int i = 0; i < auxiliary.size(); i++) {
            while (auxiliary[i].second --)
                result.push_back(auxiliary[i].first);
        }

        return result;
    }
};
