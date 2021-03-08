
#include <vector>
#include <cmath>

using namespace std;

/*
 * 比较简单的一道回溯问题，本质上就是 combination sum，只不过 nums 数组需要我们自己进行求解。
 * 
 * 3^15 = 14348907，已经大于 10^7 了，所以 nums 数组中最多也就只有 15 个数字，回溯法时间复杂度为 O(2^n)，当 n = 15 时为 32768
 * 
 * 完全能够在毫秒级内得到结果。
 */
class Solution {
public:

    bool backtracking(vector<int>& candidates, int target, int index, int sum) {

        if (sum == target) return true;

        if (index >= candidates.size()) return false;

        for (int i = index; i < candidates.size(); i++) {
            sum += candidates[i];
            if (backtracking(candidates, target, i + 1, sum)) return true;
            sum -= candidates[i];
        }
        return false;
    }

    bool checkPowersOfThree(int target) {
        vector<int> candidates;

        for (int i = 0; pow(3, i) <= 10000000; i++)
            candidates.push_back(pow(3, i));
        
        return backtracking(candidates, target, 0, 0);
    }
};