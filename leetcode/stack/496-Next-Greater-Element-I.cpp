
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

/*
 * Next Greater Number 的典型例题，只不过换成了 nums1 是 nums2 的一个子集
 * 
 * 我们对 nums2 使用单调递增栈（从栈顶到栈底元素逐渐增大）找到每一个元素右侧的最近的“大数”，并使用 hashmap 进行存储，然后遍历 nums1 去 hashmap 里面查找即可。
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> incStack;
        unordered_map<int, int> record;
        vector<int> result(nums1.size(), -1);

        for (int i = 0; i < nums2.size(); i++) {
            int element = nums2[i];

            // 当栈顶元素小于当前遍历的元素时，如果将该元素压栈，则破坏了单调递增栈的单调性，所以我们需要弹出栈顶元素，直至其满足性质。
            // 并且，对于栈顶元素来说，我们也找到了距离栈顶元素最近的、并且大于自身的元素。
            while (!incStack.empty() && incStack.top() < element) {
                record[incStack.top()] = element;
                incStack.pop();
            }
            incStack.push(element);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (record.count(nums1[i])) 
                result[i] = record[nums1[i]];
        }
        return result;
    }
};