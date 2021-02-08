
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 最少有多少只 🐸 一起 "croak" 叫，也是挺有意思的一道题目。
 * 
 * 对于 croakOfFrogs 中出现的完整的 "croak"，我们保持其计数始终为 1，因为完全有可能是同一个 🐸 一直在叫，例如 "croakcroakcroak"。
 * 
 * 我们的重点应该放在那些有重叠的子串上，例如 "crcroakoak"，这个时候我们可以统计频率，因为 "croak" 中没有重复的 word，所以有几个 'c'，就有多少只 🐸 。
 */
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string s = "croak";
        int res = 0, n = croakOfFrogs.size();
        vector<int> freq(5, 0);                      // 频率统计

        for (int i = 0; i < n; i++) {
            char current = croakOfFrogs[i];
            int index = s.find(current);

            freq[index] ++;

            // 当我们遍历的字符并不是首字母 'c'，并且在其之前的字母频率小于当前字母时，croakOfFrogs 存在乱序
            if (current != 'c' && freq[index] > freq[index - 1]) return -1;

            res = max(res, (int)(*max_element(freq.begin(), freq.end()) - *min_element(freq.begin(), freq.end())));
        }

        for (int i = 0; i < 4; i++) {
            if (freq[i] != freq[i+1]) return -1;
        }

        return res;
    }
};