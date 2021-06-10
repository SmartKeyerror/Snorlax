
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string& s) {
        int n = s.size(), result = 0;

        if (s.size() <= 2) return s.size();

        int left = 0;
        unordered_map<char, int> bucket;

        for (int right = 0; right < n; right++) {

            // 把当前遍历到的元素扔进 bucket 中
            bucket[s[right]] ++;

            // 当不满足条件时 left 不断向右移动
            while (bucket.size() > 2) {
                bucket[s[left]] --;
                if (bucket[s[left]] == 0) bucket.erase(s[left]);
                left ++;
            }
            
            result = max(result, right - left + 1);
        }
        return result;
    }
};