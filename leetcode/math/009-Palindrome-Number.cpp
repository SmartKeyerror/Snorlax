

/*
 * 求一个整型数字是否为回文数字，例如 121， 1221, 均为回文数字
 * Follow up: 不将 x 转换成 string 处理
 * 
 * 我们只需要从个位数开始构建，从后往前再 build 出一个数字，判断我们 build 出来的数字和 x 是否相等即可。
 */
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        int value = x;
        long long res = 0;

        while (value) {
            res = res * 10 + value % 10;
            value /= 10;
        }

        return res == x;
    }
};