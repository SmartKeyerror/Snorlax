
#include <limits.h>

/*
 * 非常适合拿来作为面试题的一道题目: 将一个整数反向输出，如果发生 signed-int 越界则直接返回 0。
 * Example: -123 => -321, 45678 => 87654 
 */
class Solution {
public:
    int reverse(int x) {
        int result = 0, current = x;
        while (current) {
            if (result > INT_MAX / 10 || result < INT_MIN / 10)
                return 0;
            result = result * 10 + current % 10;
            current = current / 10;
        }
        return result;
    }
};
