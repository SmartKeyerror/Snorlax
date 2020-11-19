
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * 判断一个数组中是否存在两个重复元素的索引差值不超过 k 
 * 
 * 很明显地，题目中暗含着“连续”这一要求，对于数组中连续的子数组，且其长度最大为 k 的题目，首先就应该想到滑动窗口
 * 并且，在这个过程中，我们需要能够尽快地找到重复元素，所以我们需要一个 map 或者是 set
 * 进一步地考虑，我们干脆维护一个大小为 k 的 map 或者是 set，每增加一个元素判断当前元素是否在该集合中，如果在，并且集合的大小不超过 k 的话，我们就得到了答案
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if (nums.size() == 0) return false;
        
        unordered_set<int> pool;

        for (int i = 0; i < nums.size(); i++) {

            if (pool.find(nums[i]) != pool.end())
                return true;
            
            pool.insert(nums[i]);

            if (pool.size() >= k + 1)
                pool.erase(nums[i - k]);
        }
        return false;
    }
};
