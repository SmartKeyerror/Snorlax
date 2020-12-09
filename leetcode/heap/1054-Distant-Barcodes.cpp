#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 * 挺有意思的一道题目，分离条形码，也就是将相同的元素隔开，不允许它们在一起腻腻歪歪
 * 如 [1,1,1,2,2,2] => [2,1,2,1,2,1]
 * 
 * 够统计每一个条形码出现的次数，然后在摆放条形码的时候优先选取出现次数最多的条形码，当然要避开相同条形码，类似于贪心的摆放策略
 * 
 * 在这个场景中，我们并不需要求 Top-K，只需要求 Top-2 就好了，因为如果当我们摆放完次数最多的条码之后，可能会出现 Top-1 和其相同的情况，那么此时我们需要找到 Top-2。
 */
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> frequency;
        for (int i = 0; i < barcodes.size(); i++)
            frequency[barcodes[i]] ++;
        
        priority_queue<pair<int, int>> common;
        for (auto &item : frequency)
            common.push({item.second, item.first});

        vector<int> result;

        while (common.size() >= 2) {
            pair<int, int> first, second;
            
            first = common.top();
            common.pop();

            second = common.top();
            common.pop();

            result.push_back(first.second);
            result.push_back(second.second);

            if (first.first > 1)
                common.push({first.first - 1, first.second});
            
            if (second.first > 1)
                common.push({second.first - 1, second.second});
        }

        if (!common.empty()) {
            result.push_back(common.top().second);
            common.pop();
        }
        return result;
    }
};
