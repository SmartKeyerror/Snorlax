
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 求 arr 中的最长子序列，使得子序列中每个元素的相邻元素间的绝对值恰好等于 difference。
 */
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0, n = arr.size();
        unordered_map<int, int> record;

        for (int i = 0; i < n; i++) {
            if (record.count(arr[i] - difference))
                record[arr[i]] = max(record[arr[i]], record[arr[i] - difference] + 1);
            if (record.count(arr[i]) == 0)
                record[arr[i]] = 1;
            result = max(result, record[arr[i]]);
        }
        return result;
    }
};