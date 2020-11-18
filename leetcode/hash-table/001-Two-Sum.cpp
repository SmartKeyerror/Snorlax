#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 非常经典的查找表问题，我们以 nums[i] 为 key, i 为 value 构造一个查找表，在该表中寻找 target - nums[i]
 * 这道题的一个小的陷阱就是我们不能直接使用 nums 中全部的值来初始化 hashmap，因为 nums 中可能存在重复元素
 * 所以，我们必须在初始化数据的同时进行查找
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                return {i, hashmap[target - nums[i]]};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};
