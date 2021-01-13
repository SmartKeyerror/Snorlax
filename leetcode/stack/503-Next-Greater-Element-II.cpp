
#include <vector>
#include <stack>

using namespace std;

/*
 * 在一个环形数组中寻找 Next Greater Number，虽然是一个环形数组，但是并不是很想利用环形队列的那种方式寻找索引值。
 * 
 * 反正对于环形数组而言，只是多了一圈儿而已，那么我们就将 nums 数组扩大一倍，例如将 [1, 2, 3, 4] 变成 [1, 2, 3, 4, 1, 2, 3]
 * 
 * 最后一个元素在此题中可以不用考虑，因为自己是不会比自己要大的。
 * 
 * 如此一来，我们用单调递增栈（从栈顶到栈底元素单调递增）遍历一遍扩充后的数组即可。
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size - 1; i++)
            nums.push_back(nums[i]);
        
        stack<int> incStack;
        vector<int> result(size, -1);

        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            while (!incStack.empty() && nums[incStack.top()] < element) {
                if (incStack.top() < size && result[incStack.top()] == -1)
                    result[incStack.top()] = element;
                incStack.pop();
            }
            incStack.push(i);
        }
        return result;
    }
};
