
#include <vector>

using namespace std;


/*
 * 求解在一个 nums 数组中，出现次数超过 ⌊n / 2⌋ （向上取整）的 num。题目保证该 num 存在
 * 
 * 可使用 Boyer Moore Majority Vote Algorithm 进行实现，简单的来说就是投票，不过投票过程非常巧妙。
 * 
 * 首先我们定义 2 个变量: count 和 major。其中 count 表示 majority num 出现的次数，初始化为 0，major 就是我们要找到的那个出现次数过半的元素。
 * 
 * 在最开始的时候，major 随便指定一个数，一般就是数组或者流中的第一个元素。遇到和 major 相同的元素 count ++，反之则 --。当然我们不会让 count 减为负数
 * 
 * 当 count 为 0 的时候说明我们找到的 major 是个假货，此时重新制定 major。
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, major = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) major = nums[i];
            if (nums[i] == major) count ++;
            else count --;
        }
        return major;
    }
};