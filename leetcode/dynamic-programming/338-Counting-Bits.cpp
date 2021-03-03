
#include <vector>

using namespace std;

/*
 * 给定一个非负整型 num， 求解 0<=i<=num 这 num + 1 个数字的二进制格式的 1 的数量
 * 
 * 0:  0000 0000 => 0     
 * 1:  0000 0001 => 1, 奇数
 * 
 * 2:  0000 0010 => 1, 偶数     
 * 3:  0000 0011 => 2, 奇数
 * 
 * 4:  0000 0100 => 1, 偶数
 * 5:  0000 0101 => 2, 奇数
 * 6:  0000 0110 => 2, 偶数
 * 7:  0000 0111 => 3, 奇数
 * 
 * 8:  0000 1000 => 1, 偶数
 * 9:  0000 1001 => 2, 奇数
 * 10: 0000 1010 => 2, 偶数
 * 11: 0000 1011 => 3, 奇数
 * 12: 0000 1100 => 2, 偶数
 * 13: 0000 1101 => 3, 奇数
 * 14: 0000 1110 => 3, 偶数
 * 15: 0000 1111 => 4, 奇数
 * 
 * 16: 0001 0000 => 1, 偶数
 * 
 * 所以，如果 memory[i] 表示数字 i 的二进制中存在多少个 1 的话
 * 
 * 那么当 i 为偶数的时候，memory[i] = memory[i/2]； 当 i 为奇数的时候，memory[i] = memory[i/2] + 1;
 * 
 * 
 * 另一种解法是直接使用 dp 来求解，假设我们要求 170 中有多个 bit 1，那么将 170 的最后一位去掉，也就是右移一位，得到 8
 * 
 * 假设 85 中存在 4 个 1 bit，那么此时我们只需要查看 170 的最后一位是否是 1 即可。
 * 
 */
class Solution {
public:

    // 另一种解法是直接使用 dp 来求解，假设我们要求 170 中有多个
    vector<int> dpSolution(int num) {
        if (num == 0) return {0};
        vector<int> memory(num + 1, 0);
        memory[0] = 0;

        for (int i = 1; i <= num; i++)
            memory[i] = memory[i>>1] + (i & 1);
        
        return memory;
    }

    vector<int> easySolution(int num) {
        if (num == 0) return {0};

        vector<int> memory(num + 1, 0);
        memory[0] = 0;

        for (int i = 1; i <= num; i++)
            memory[i] = i % 2 == 0 ? memory[i/2]: memory[i/2] + 1;
        
        return memory;
    }

    vector<int> countBits(int num) {
        return easySolution(num);
        return dpSolution(num);
    }
};
