
#include <vector>

using namespace std;

/*
 * n=1: 10
 * n=2: 9 * 9 + 10 = 91
 * n=3: 9 * 9 * 8 + 91 = 739
 * n=4: 9 * 9 * 8 * 7 + 739 = 5275
 * 
 * 说白了就是一个数字排列问题，假设有一个 4 位数 ABCD，那么一共有 9 * 9 * 8 * 7 个 4 位数字，使得各个位数都不相同
 * 
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> memory(n+1, 0);
        memory[0] = 1, memory[1] = 10;
        for (int i = 2; i <= n; i++) {
            int current = 9, choices = 9;
            while (choices > 10 - i) {
                current *= choices;
                choices --;
            }
            memory[i] = current + memory[i-1];
        }
        return memory[n];
    }
};
