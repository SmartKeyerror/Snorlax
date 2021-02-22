
#include <vector>
#include <set>

using namespace std;

/*
 * 一道比较典型的滑动窗口问题。在此题中，我们关心的是窗口中的最大值以及最小值，并且我们需要动态的更新窗口中的最大值和最小值。
 * 
 * 同时，在窗口滑动的过程中，可能还需要将最左侧的元素从容器中弹出。符合这一数据结构特征的只剩下 multiset 了。
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
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
};