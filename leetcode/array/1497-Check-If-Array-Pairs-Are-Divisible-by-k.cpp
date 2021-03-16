
#include <vector>
#include <unordered_map>

using namespace std;


/*
 * 如果我们需要 (a + b) % k == 0，那么 a、b 会有如下两种情况:
 * 
 * - a % k == 0 && b % k == 0，例如 a = 9, b = 6, k = 3，a 和 b 都能被 3 整除，那么 a + b 的结果也一定能被 3 整除。
 * - a % k + b % k = k，例如 a = 10, b = 5，k = 3, 10 % 3 = 1, 5 % 3 = 2, 1 + 2 的结果为 3 ，与 k 相同。 
 * 
 * 因此，我们统计 arr 数组中所有元素对 k 取余的结果，并统计频次，然后尝试进行配对。
 * 
 * 当 key 为 0 的时候，我们得看其频率是否为偶数，若不是偶数，返回 false。
 * 当 key 不为 0 的时候，那么就看 k - key 的频次和 key 的频次是否相同，若不相同，返回 false.
 */
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        // 因为 arr 中有负数，所以我们每一个元素都加上一个 k ，把负号干掉
        for (auto num : arr) freq[(num % k + k) % k] ++;

        if (freq[0] & 1) return false;

        for (int i = 1; i <= k / 2; i++) {
           if (freq[i] != freq[k-i]) return false;
        }
        return true;
    }
};
