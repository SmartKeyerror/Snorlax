
#include <vector>
#include <stack>

using namespace std;

/*
 * 单调栈的有一个典型应用，求直方图中的最大面积。
 * 
                 +--+
                 |  |
              +--+  |
              |  |  |
           +--+  |  +--+
           |  |  |  |  |
        +--+  |  |  |  +--+
        |  |  |  |  |  |  |
     +--+  |  |  |  |  |  |
     |  |  |  |  |  |  |  |
     |  |  |  |  |  |  |  |
+----+--+--+--+--+--+--+--+------->

 * 假设我们有如上直方图，多个直方图所组成的面积是由那个最短的柱子所决定的，假设我们只有两根柱子，一个高度为 5，一个高度为 4，那么最大面积就是 min(5, 4) * (5-4+1) = 8。
 * 
 * 所以说，较短的那根柱子将是我们重点关注的对象。所以，我们需要维护一个单调递减栈(从栈顶到栈底单调递减)，一旦我们发现了比栈顶要短的柱子，弹出栈顶元素，尝试计算最大面积。
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> descStack;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            if (descStack.empty() || heights[i] > heights[descStack.top()])
                descStack.push(i);      // push index
            else {
                int h = heights[descStack.top()]; 
                descStack.pop();
                int w = descStack.empty() ? i : i - descStack.top() - 1;
                res = max(res, h * w);
                i --;
            }
        }
        return res;
    }
};