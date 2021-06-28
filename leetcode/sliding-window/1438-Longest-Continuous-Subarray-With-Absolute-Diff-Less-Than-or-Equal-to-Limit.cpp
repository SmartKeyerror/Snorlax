
#include <vector>
#include <set>
#include <map>

using namespace std;

/*
 * 一道比较典型的滑动窗口问题。在此题中，我们关心的是窗口中的最大值以及最小值，并且我们需要动态的更新窗口中的最大值和最小值。
 * 
 * 同时，在窗口滑动的过程中，可能还需要将最左侧的元素从容器中弹出。符合这一数据结构特征的只剩下 multiset 了。
 * 
 * 同时，也可以使用 map 来完成，只需要记录下 num 的出现频次即可。
 * 
 * 不管是使用 multiset 还是 map 来实现，其时间复杂度均为 O(nlogn)，空间复杂度为 O(n)
 */
class Solution {
public:
    int multisetSolution(vector<int>& nums, int limit) {
        multiset<int> window;
        int n = nums.size(), result = 1, left = 0, right = 0;

        while (right < n) {
            window.insert(nums[right]);
            while (*window.rbegin() - *window.begin() > limit) {
                // 注意，这里不能写 window.erase(nums[left]), 这样会将值为 nums[left] 的所有元素从 window 中删除
                // 而我们的本意只是删除一个，所以用迭代器的方式实现
                window.erase(window.find(nums[left]));
                left ++;
            }
            result = max(result, right - left + 1);
            right ++;
        }
        return result;
    }

    int mapSolution(vector<int>& nums, int limit) {
        map<int, int> window;
        int result = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            window[nums[right]] ++;

            // 判断当前窗口是否满足要求
            while (window.rbegin()->first - window.begin()->first > limit) {
                window[nums[left]] --;
                if (window[nums[left]] == 0) window.erase(nums[left]);
                left ++;
            }

            // 此时窗口满足要求，更新结果
            result = max(result, right - left + 1);
        }
        return result;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        // return multisetSolution(nums, limit);
        return mapSolution(nums, limit);
    }
};