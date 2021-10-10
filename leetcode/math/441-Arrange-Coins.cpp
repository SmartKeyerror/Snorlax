#include <iostream>

using namespace std;


/*
 * 一道等差数列和问题，也就是求满足 1+2+3+...K <= n 的 K 的最大值。
 * 1+2+3+...K = (K^2 + K) / 2，也就是说，我们要求 (K^2 + K) <= n 的最大 K 值。
 * 
 * 暴力解就是从 1 开始枚举 K 的取值，值得找到满足条件的最大 K。
 * 
 * 另一种方式就是使用二分搜索，由于阶数是 2，所以时间复杂度可以优化至 logn。
 * 
 * 这道题其实和 sqrt(x) 非常类似。
 *  
 */
class Solution {
public:
    int arrangeCoins(int n) {

        if (n == 0)
            return 0;

        int result = 0;
        int left = 1, right = n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if ((mid * mid + mid) / 2 == n)
                return mid;
            else if ((mid * mid + mid) / 2 < n)
                left = mid + 1;
            else right = mid - 1;
        }

        return right;
    }
};