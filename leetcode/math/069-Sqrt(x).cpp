

/*
 * 开根号设计，mySqrt(8) = 2, 即返回整型。
 * 
 * 也就是说，我们只需要找到一个数 k，使得 k * k <= x，并且 k 有最大值即可。
 * 
 * 二分搜索解决，初始区间就是 [1, x]。
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1, right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // if (mid * mid == x) return mid; 这样写会有整型溢出的问题，所以改用除法
            
            if (x / mid == mid) return mid;
            else if (x / mid < mid) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};