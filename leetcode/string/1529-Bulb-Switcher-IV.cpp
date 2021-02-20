
#include <string>

using namespace std;

/*
 * 挺有意思的一道题目。从初始化状态 "00000" 进行翻转，直到等于 target。翻转是指从第 i 个元素开始，一直到字符串的末尾，'0' 变成 '1'，'1' 变成 '0'。
 * 
 * 当 target 为 "10111" 时，我们可以这样进行翻转:
 * 
 * "00000" => "00111"，翻转索引为 2 后面的所有字符。
 * "00111" => "11000"，翻转索引为 2 后面的所有字符。
 * "11000" => "10111"，翻转索引为 1 后面的所有字符。
 * 
 * 1 <= target.length <= 10^5，因此，我们必须在 O(n) 的时间复杂度内完成。如果不考虑 target 的长度的话，BFS 有可能完成。
 * 
 * 因为我们每次翻转都是针对 [i...n-1] 这个区间的，也就是说，假设 [x..i] 以及 [i...k] 这一块儿区间的值不一样的话，我们一定需要一次翻转来完成。
 */
class Solution {
public:
    int minFlips(string target) {
        int result = 0, current = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] - '0' != current) {
                result ++;
                current = target[i] - '0';
            }
        }
        return result;
    }
};