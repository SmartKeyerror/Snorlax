
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size(), shards = n / k;

        if (n % k != 0) return false;

        int start = 0;
        map<int, int> freq;     // 需要找到当前 freq 的最小值，所以使用 TreeMap，而不是 HashMap

        for (auto num : nums) freq[num] ++;

        // 一共有 shards 个分片，所以循环这么多次
        for (int i = 0; i < shards; i++) {
            auto it = freq.begin();
            int currentStart = it->first;

            for (int j = currentStart; j < currentStart + k; j++) {
                if (freq.count(j) == 0) return false;
                freq[j] --;
                if (freq[j] == 0) freq.erase(j);
            }
        }
        return true;
    }
};