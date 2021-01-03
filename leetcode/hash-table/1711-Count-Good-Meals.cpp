
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
        
        if (deliciousness.size() <= 1) return 0;
        
        int result = 0;
        int mod = 1000000007;
        unordered_map<int, int> record;


        sort(deliciousness.begin(), deliciousness.end());
        record[deliciousness[0]] ++;
        
        for (int i = 0; i < deliciousness.size(); i++) {
            for (int p = 0; p <= 21; p++) {

                if ((int)pow(2,p) > 2 * deliciousness[i]) break;

                int target = (int)(pow(2, p)) - deliciousness[i];
                if (record.count(target) != 0) {
                    result += record[target] % mod;
                    result = result % mod;
                }
            }
            record[deliciousness[i]] ++;
        }
        return result;
    }
};