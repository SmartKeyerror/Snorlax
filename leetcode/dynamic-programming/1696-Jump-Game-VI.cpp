
#include <vector>
#include <queue>

using namespace std;


/*
 * 1 <= nums.length, k <= 10^5，也就是说，O(n^2) 的 dp 解法必然超时。
 * 
 * dp 解法思路很简单，设 dp[i] 表示跳到第 i 个石子所能获得的最大金币数量，那么状态转移方程为:
 * 
 *   dp[i] = max(dp[i-k], dp[i-k+1], dp[i-k+2],...,dp[i-1]) + nums[i]
 * 
 * 很明显地，这是一个 O(nk) 的解法，结合题目的数据规模，dp 走不通
 * 
 * 那么让我们再看一下 dp[i] = max(dp[i-k], dp[i-k+1], dp[i-k+2],...,dp[i-1]) + nums[i] 这个状态转移方程
 * 
 * 假设 nums = [1,-1,-2,4,-7,3], k = 2, i = 2
 * 
 * [1 -1] -2 4 -7 3
 *         ↑
 * 
 * 1 [-1 -2] 4 -7 3
 *           ↑
 * 
 * 1 -1 [-2 4] -7 3
 *             ↑
 * 
 * 1 -1 -2 [4 -7] 3
 *                ↑
 * 
 * 这不就类似于一个滑动窗口最大值问题吗?
 * 
 */
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> scores(n, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (i - k > 0) {
                if (!dq.empty() && dq.front() == scores[i-k-1])
                    dq.pop_front();
            }
            int old = dq.empty() ? 0 : dq.front();
            scores[i] = old + nums[i];
            while (!dq.empty() && dq.back() < scores[i])
                dq.pop_back();
            dq.push_back(scores[i]);
        }
        return scores[n-1];
    }
};
