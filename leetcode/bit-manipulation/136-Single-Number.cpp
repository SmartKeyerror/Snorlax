
#include <vector>

using namespace std;

/*
 * 这道题目有意思的地方就在于只有 1 个数出现了一次，其它的都出现了两次，如果我们有一种方式能够“两两碰对”进行消融的话，只需要遍历一遍数组即可得到答案
 * 并且两两碰对的过程中需要忽略元素之间的顺序，也就是说　[2, 2, 3] 和　[2, 3, 2] 的结果是一样的
 * 答案就是 异或。异或这一运算通常会应用在诸如找不同、计算数据差异的领域中，本质上就是找不同: 
 * 
 *  0 ^ 0 = 0, 
 *  1 ^ 1 = 0, 
 *  0 ^ 1 = 1, 
 *  1 ^ 0 = 1
 * 
 * 并且，异或运算满足结合律和交换律，也就是说，a ^ b ^ c = a ^ c ^ b，a ^ a = a，并且 ０ ^ a = a
 * 
 * 详细解释见: https://en.wikipedia.org/wiki/Exclusive_or
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            res ^= nums[i];
        
        return res;
    }
};