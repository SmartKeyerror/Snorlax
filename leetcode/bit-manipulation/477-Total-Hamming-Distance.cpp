
#include <vector>

using namespace std;

/*
 * 暴力解法超时，必须使用 O(n) 的时间复杂度来解决，先看看 Example 之间的规律:
 * 
 * 0100
 * 1110
 * 0010
 * 
 * 第 0 位都是 0，所以这三个数对于第 0 位而言的总汉明距离为 0。
 * 
 * 第 1 位有两个数是 1,1 个数是 0，按照排列组合，一共有两种组合方式，故第 1 位的总汉明距离为 2。
 * 
 * 第 2 位同理，所以汉明距离也是 2。
 * 
 * 第 3 位有两个数是 0， 1 个数是 1，按照排列组合共有两种组合方式，所以第 3 位的汉明距离为 2。
 * 
 * 最后相加得 6，和示例给出的答案相同。
 * 
 * 那么问题来了，对于第 i 位而言，假设有 x 个 0， y 个 1，共有多少种组合? 
 * 
 * 答案是 x * y，而又有 x + y = nums.size()，所以组合数为 x * (nums.size() - x) 这个多个。
 * 
 * 所以我们只需要找到 nums 数组中每个数的第 i 位一共有多少个 0，或者是多少个 1 即可。
 * 
 * Runtime: 76 ms, faster than 79.33% of C++ online submissions for Total Hamming Distance.
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0, n = nums.size();

        // 注意最高位为符号位，而题目中给出了 0 <= nums[i] <= 10^9 这个条件，所以第 31 位一定是相同的，因为都是正数
        for (int i = 0; i < 31; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                // 我们统计 `1` 的个数
                if ((1 << i) & nums[j]) count ++;
            }
            result += count * (n - count);
        }
        return result;
    }
};

