
#include <vector>
#include <stack>

using namespace std;

/*
 * 单调栈的又一个典型应用，求直方图中的最大面积。
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





/*
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
       0  1  2  3  4  5  6

 * 对于柱子 0 来说，完全包含柱子 0 的矩形为 0-6，那么完整包含柱子 1 的最大矩形就是 (6 - 0 + 1) * hight(柱子 0)
 * 
 * 对于柱子 1 来说，完全包含柱子 1 的矩形为 1-6，那么完整包含柱子 2 的最大矩形就是 (6 - 1 + 1) * hight(柱子 1)
 * 
 * 对于柱子 2 来说，完全包含柱子 2 的矩形为 2-5，那么完整包含柱子 3 的最大矩形就是 (5 - 2 + 1) * hight(柱子 2)
 * 
 * 对于柱子 3 来说，完全包含柱子 3 的矩形为 3-4，那么完整包含柱子 4 的最大矩形就是 (4 - 3 + 1) * hight(柱子 3)
 * 
 * 所有，对于每一根柱子来说，我们更关心它左边儿更短的柱子，和右边更短的柱子，这样我们才能知道每一根柱子能够扩展到哪里去
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0, n = heights.size();

        stack<int> st;

        for (int i = 0; i < heights.size(); i++) {

            // 此时不满足严格单调递减的性质
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                int top = st.top();
                st.pop();
                int prev = st.empty() ? -1 : st.top();

                // 计算以 top 为中心的最大矩形
                int current = (i - prev - 1) * heights[top];

                result = max(result, current);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int prev = st.empty() ? -1 : st.top();

            // 计算以 top 为中心的最大矩形
            int current = (n - prev - 1) * heights[top];

            result = max(result, current);
        }
        return result;
    }
};