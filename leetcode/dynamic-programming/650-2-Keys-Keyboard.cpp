
#include <vector>
#include <limits.h>

using namespace std;

/*
 * 这是一道非常切合生活的一道问题，给定目标数量 n， 每次能复制小于等于当前面板中存在的字符数量，问怎么复制粘贴使得操作次数最少
 * 
 */
class Solution {
public:
    int minSteps(int n) {
        vector<int> memory(n + 1, INT_MAX);
        memory[0] = 0, memory[1] = 0;

        for (int i = 2; i <= n; i++) {
            for (int j = i; j > 1; j--) {
                if (i % j == 0)
                    memory[i] = min(memory[i], memory[i/j] + j);
            }
        }
        return memory[n];
    }
};
