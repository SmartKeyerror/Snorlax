
#include <limits.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 时空复杂度均为 O(n)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;

        int left = 0;
        int result = 0;
        unordered_set<char> window;

        for (int right = 0; right < s.size(); right++) {
            // 当窗口不满足条件时，不断地收缩左侧边界
            while (left < s.size() && window.count(s[right])) {
                window.erase(s[left]);
                left ++;
            }
			// 此时将 s[right] 纳入窗口后必将满足条件
            window.insert(s[right]);
            result = max(result, right - left + 1);
        }

        return result;
	}
};
