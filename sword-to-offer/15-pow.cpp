
/*
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
 * 
 * x^n = x^(n/2) * x^(n/2)，n 为偶数
 * x^n = x^(n/2) * x^(n/2) * x，n 为奇数
 * 
 * 递归终止条件，n == 0 或者是 n == 1 或者是 n == 2，直接返回 1、x 或者是 x * x
 * 
 * 另外还需要考虑 n 为负数的情况，这时候我们计算 n 为正数的情况，然后取倒数即可。
 * 
 * 然后还得注意输入中 n = -2147483648 的情况，这时候使用 0 - n 的话就会出现整型溢出，所以使用 long long 转型
 * 
 * 题目本身不难，但是边界情况比较多
 */

class Solution {
private:
    double powOfPositiveNumber(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;

        double half = myPow(x, n/2);

        if (n & 1) {        // 奇数
            return half * half * x;
        } else {            // 偶数
            return half * half;
        }
    }
public:
    double myPow(double x, int n) {
        return n >= 0 ? powOfPositiveNumber(x, n) : 1 / powOfPositiveNumber(x, (long long)0 - n);
    }
};