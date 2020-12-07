
#include <vector>

using namespace std;

/*
 * "奇偶排序"，奇数落在索引为奇数的位置上，偶数落在索引为偶数的位置上，要求 O(n) 时间内搞定
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0, odd = 1, n = A.size();

        while (even < n && odd < n) {
            if (A[even] % 2 != 0 && A[odd] % 2 == 0) {
                swap(A[even], A[odd]);
                even += 2, odd += 2;
                continue;
            }
            if (A[even] % 2 == 0)
                even += 2;
            if (A[odd] % 2 != 0)
                odd += 2;
        }
        return A;
    }
};
