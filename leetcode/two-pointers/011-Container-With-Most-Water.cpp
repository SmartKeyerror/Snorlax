
#include <vector>

using namespace std;

/*
 * 以列表 height 索引为横轴，值为纵轴构成一个个的容器，求容器最大体积(也就是求最大面积)
 * 2 <= n <= 3 * 10^4， 也就是说，我们必须在 O(n) 的时间界别内解决问题
 * 
 * 让我们想想关于数组问题有哪些常见的解题方案: 排序、Silding Window, Two Pointers, HashMap, DP, backtracking, greddy, ...
 * 
 * 想了想，似乎只有 Two Pointers 有那么一丝丝可能，那么问题就变成 同向指针 还是 对撞指针 ?
 * 
 * 同向指针的话 O(n^2) 没跑，肯定GG。再来看对撞指针。对撞指针的精髓就在于何时移动 left、right 指针
 * 
 * 设 left、right 指针初始化时指向 height[0]、height[n-1]，使用 min(height[left], height[right]) * (right - left) 计算一次面积，保存一下结果
 * 
 * 问题来了，是让 left 向右移动，还是让 right 向左移动? 因为我们要求最大面积，那么当长度必然减少 1 的情况下，高度越大越好
 * 所以我们应该让高度更小的指针移动，假如 height[left] < height[right]，那么 left ++;
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right -  left);
            res = max(res, currentArea);
            height[left] < height[right] ? left ++: right --;
        }
        return res;
    }
};
