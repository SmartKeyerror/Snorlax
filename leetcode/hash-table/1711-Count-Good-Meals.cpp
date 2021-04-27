
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

/*
 * 求 deliciousness 中两数之和为 2 的 n 次幂的所有组合。
 * 
 * 回溯法GG，还没发现为什么得到错误的结果。
 * 
 * 可以看做是两数之和的改版，只不过此时的“和”并不是一个固定值，而是 2，4，8,16,32,64，... 这样的数，题目中给出了 deliciousness[i] 最为值为 2^20，
 * 所以我们所判定的和最大值为 2^21。
 */
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        
        // 图省事，所以直接使用长整型
        long long result = 0;
        unordered_map<int, int> record;

        for (auto v : deliciousness) {
            for (int p = 0; p <= 21; p++) {
                int find = (1 << p) - v;
                if (record.count(find)) {
                    result += record[find];
                }
            }
            record[v] ++;
        }
        int mod = 1e9 + 7;
        return result % mod;
    }
};