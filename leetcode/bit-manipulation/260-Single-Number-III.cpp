
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * [1, 1, 2, 2, 3, 4]，异或的结果为 7，xor 的本质是寻找两个数字不同的 bit 位。
 * 7 转换成二进制为 0111，也就是说 3 和 4 的第 1 位、第 2 位 和第 3 位都不相同，那么我们随便选择一位来对 nums 进行分组
 * 以第 1 位为例，所有第 1 是 0 的分成一组，所有第 1 位是 1 的分成一组，如此一来，nums 数组必然会被分成两组，而 3 和 4 和分别在两组中
 * 而 [1, 1]、[2, 2] 这些重复数字必然会被分到同一组，那么我们就可以使用 136 的方案来获取 a 和 b 了
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_res = 0;

        // 得到只出现 1 次的两个数的异或结果
        for (int i = 0; i < nums.size(); i++) {
            xor_res ^= nums[i];
        }

        // 寻找 a、b 两个数不同的那一位，以此作为区分点，将 nums 分成两组
        int diff = 1;
        while ((xor_res & diff) == 0) {
            diff = diff << 1;
        }
    
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & diff) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }

        return {a, b};
    }
};
