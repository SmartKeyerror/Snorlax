
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
 * 正如 Hint 中提到的，首先计算 s[i] 与 t[i] 之间的绝对距离，得到 dis 数组，然后用滑动窗口找到该数组中的最长子数组，使得子数组的和小于等于 maxCost。
 */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> dis(n, 0);

        for (int i = 0; i < n; i++)
            dis[i] = abs(s[i] - t[i]);

        int left = 0, right = 0, sum = 0, res = 0;

        while (right < n) {
            sum += dis[right];
            if (sum <= maxCost) res = max(res, right - left + 1);
            else 
                sum -= dis[left++];
            right ++;
        }
        return res;
    }
};