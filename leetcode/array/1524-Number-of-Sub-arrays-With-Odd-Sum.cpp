
#include <vector>

using namespace std;


/*
 * 寻找和为奇数的所有子数组的个数，显然需要使用 prefixSum 解决。不过在计算 prefixSum 的过程中，我们需要记录一些东西。
 * 
 * 以 [1, 3, 5] 为例，得到的 prefixSum 为 [1, 4, 9]，奇偶性质为 [奇数，偶数，奇数]
 * 
 * 我们知道 偶数 - 奇数 = 奇数，奇数 - 偶数 = 奇数，所以我们只需要统计一下前面出现的奇数数量和偶数数量即可。
 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long result = 0;
        int oddCounts = 0, evenCounts = 0, n = arr.size(), mode = 1e9 + 7;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];

        if (arr[0] & 1) {
            oddCounts ++, result ++;
        }
        else evenCounts ++;

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];

            // 当 prefixSum[i] 为 奇数 时，我们更关注它之前一共有多少个偶数
            if (prefixSum[i] & 1) {
                result += evenCounts + 1;
                oddCounts ++;
            } else {                        // 当 prefixSum[i] 为 偶数 时，我们更关注它之前一共有多少个奇数
                result += oddCounts;
                evenCounts ++;
            } 
        }

        return result % mode;
    }
};