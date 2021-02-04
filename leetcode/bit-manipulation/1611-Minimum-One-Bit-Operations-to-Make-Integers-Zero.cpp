


/*
 * 求将整型数字 n 按照一定的位操作变为 0 的最小操作步骤，一共有两种操作方式:
 * - 翻转 n 的二进制表示中最右侧位（第 0 位）
 * - 如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位
 * 
 * 本质上其实就是在考察格雷码的应用，异或+移位操作即可。具体可参考:
 * 
 * https://oi-wiki.org/misc/gray-code/
 */
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
