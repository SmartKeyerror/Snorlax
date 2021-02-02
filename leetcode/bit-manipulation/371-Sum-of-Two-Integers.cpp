

/*
 * 不用 `+` 操作符实现整型的加法
 * 
 * 首先来看看 &、|、^ 这 3 个操作符该如何使用
 * 
 * ^ 可以实现不带进位的加法器，只有当两个数不同时，^ 的结果才为 1，否则为 0:
 *    0000 1010
 *    0000 1111
 *   -----------
 *    0000 0101
 * 
 * & 可以仅实现进位操作，a & b 的结果在左移一位，就是进位的结果值:
 * 
 *   0000 1010
 *   0000 1111
 *  ------------
 *   0000 1010  =>(左移一位) 0001 0100
 * 
 * 然后我们把两个值加起来就完事儿了。
 */
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b & 0x7fffffff) << 1;
        return getSum(sum, carry);
    }
};