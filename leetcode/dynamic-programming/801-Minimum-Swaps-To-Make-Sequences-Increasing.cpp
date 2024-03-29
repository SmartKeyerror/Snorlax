
#include <vector>

using namespace std;


/*
 * 如果我们使用 dp[i] 来表示 [0...i] 为严格递增序列的最小交换次数的话，会发现状态转移方程有一些 tricky。
 * 
 * 其原因在于，dp[i] 和什么有关系? dp[i-1] 吗? dp[i-1] 的选择会直接影响到 dp[i] 的值，
 * 
 * 这是因为当前一个元素选择交换元素和不选择交换元素，会对 A、B 两个数组的递增性产生直接的关联关系。
 * 
 * 既然是 change or not change 的问题，我们干脆将 dp 数组定义成 dp[i][2]。
 * 
 * dp[i][0] 表示 [0...i] 为严格递增序列并且当前 i 需要交换的最小交换次数，dp[i][1] 则表示 [0...i] 为严格递增序列并且当前 i 不需要交换的最小交换次数。
 * 
 * 因此，dp[0][0] = 1, 因为第 0 个元素必须要交换，所以交换次数为 1；dp[0][1] = 0，因为第 0 个元素不需要交换，所以为 0。这和我们的 dp[i][2] 数组定义是一致的。
 * 
 * 现在来看状态转移方程。首先来看 dp[i][0] 该如何取值。dp[i][0] 表示当前位置 i 的元素必须要交换才能满足递增性质，也就是说，A[i] > B[i-1] && B[i] > A[i-1]。
 * 
 * [1, 2, 5, 4]
 * [1, 2, 3, 7]
 * 
 * 假设 i = 3，A[3] 和 B[3] 以及 A[2]、B[2] 必须要满足 A[3] > B[2] && B[3] > A[2] 才能保证 [0...3] 两者是严格递增的。
 * 
 * 同时，因为我们交换了第 i 个元素，所以第 i-1 个元素不需要被交换，所以 dp[i][0] = dp[i-1][1] + 1。
 * 
 * 再来看 dp[i][1] 如何取值，dp[i][1] 表示当前位置 i 的元素不需要交换满足递增性质，那么假设出现了 [5, 4] 和 [3, 7] 这样的情况 , 4 和 7 不能被交换，那么只能交换第 i-1 个元素了。
 */
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(2, n));

        dp[0][0] = 1, dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i-1] && B[i] > B[i-1]) {
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = dp[i-1][1];
            }

            if (A[i] > B[i-1] && B[i] > A[i-1]) {
                dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
                dp[i][1] = min(dp[i][1], dp[i-1][0]);
            }
        }

        return min(dp[n-1][0], dp[n-1][1]);
    }
};