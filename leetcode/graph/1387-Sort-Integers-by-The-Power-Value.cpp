
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 求 lo ~ hi 之间这 hi - lo + 1 个数的 power 排序。一个数的 power 是指将其通过某种方式转换成 1 的步骤数量，规则如下:
 * 
 * if x is even then x = x / 2
 * if x is odd then x = 3 * x + 1
 * 
 * the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
 * 
 * 如果我们的 x 有多个话的，那么完全可以组成一幅类似于鱼骨图这样的东西，然后求出每一条路径长度即可。
 * 
 * 同样也可以使用自顶向下的记忆化搜索实现，也就是 DP。
 */
class Solution {
private:
    unordered_map<int, int> memory;
    int countSteps(int x, int count) {
        if (x == 1) return count;

        count ++;

        if (x & 1) x = 3 * x + 1;
        else x = x / 2;

        if (memory.count(x)) return count + memory[x];
        return countSteps(x, count);
    }

    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> result;
        for (int i = lo; i <= hi; i++) {
            memory[i] = countSteps(i, 0);
            result.push_back({memory[i], i});
        }

        sort(result.begin(), result.end(), compare);
            
        return result[k-1].second;
    }
};