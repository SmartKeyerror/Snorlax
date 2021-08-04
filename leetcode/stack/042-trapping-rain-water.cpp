
#include <stack>
#include <vector>

using namespace std;

/*
 * 在 柱状图中最大的矩形 的那道问题中，对于每根柱子，如果计算以该柱子为高度的最大矩形的话，那么就需要看它向左能扩展多远，向右扩展多远。
 * 换而言之，只要我们知道了每一根柱子离它左边和右边最近的且小于它的柱子，我们就能知道以当前柱子为高度的矩形面积是多少了。因此可以使用单调栈来解决。
 * 
 * Largest Rectangle In Histogram 可以使用严格单调递减栈实现，也就是从栈顶到栈底的元素严格递减。对于相同的柱子可以进行覆盖：
 * 
 *              ┌────┐
 *              │    │
 *      ┌───┬───┤    │
 *      │   │   │    │
 *  ┌───┤   │   │    │
 *  │   │   │   │    │
 *  │   │   │   │    │
 * ─┴───┴───┴───┴────┴────────►
 *    k   i   j
 * 
 * 如上图所示，假设 j 覆盖了 i，当我们计算以 j 为高度的最大矩形时，会将 i 柱子包含在内，所以不会出现遗漏的问题。
 * 
 * 而对于 Trapping Rain Watter 来说，以柱子 i 为 “杯底” 的话，那么我们只需要知道离它左边和右边最近的且大于它的柱子，我们就知道这个 “杯子” 能接多少水了。
 * 
 * 所以，我们可以使用一个严格的单调递增栈来完成，也就是栈顶到栈底严格单调递增。
 */
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;

        int result = 0;

        for (int i = 0; i < height.size(); i++) {

            // 此时不满足栈顶到栈底严格单调递增，换句话说，我们或许能接到新的雨水
            while (!st.empty() && height[i] >= height[st.top()]) {
                int j = st.top();
                st.pop();

                if (st.empty()) break;

                int k = st.top();

                // 此时我们计算的是以柱子 j 为杯底的最大雨水量

                // 计算最短的边沿
                int minH = min(height[k], height[i]);

                /*
                 *           ┌───┐
                 *   ┌───┐   │   │
                 *   │   │   │   │
                 *   │   ├───┤   │
                 * ──┴───┴───┴───┴──►
                 *     k   j   i
                 * 如上图，以 j 为杯底能够承接的最大雨水除了要考虑最短的边沿以外，还需要考虑杯底本身的高度和在最短边沿之间的差值
                 */
                result += (minH - height[j]) * (i - k - 1);
            }
            st.push(i);
        }
        return result;
    }
};