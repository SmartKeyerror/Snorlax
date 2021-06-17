

class Solution {
public:
    int mySqrt(int x) {

        if (x <= 1) return x;

        int left = 0, right = x;

        // 在 [left, right] 这个闭区间上进行
        while (left <= right) {
            
            int mid = left + (right - left) / 2;

            // mid * mid 会有整型溢出的问题，所以使用除法

            if (x / mid > mid) left = mid + 1;
            else if (x / mid < mid) right = mid - 1;
            else if (x / mid == mid) return mid;
        }
        
        // 此时该返回 left 还是 right ?
        // 循环结束后，left > right，题目要求向下取整，所以应该返回 right
        return right;
    }
};