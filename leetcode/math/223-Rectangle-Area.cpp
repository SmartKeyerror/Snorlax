
using namespace std;

#include <cmath>
#include <algorithm>

/*
 * 挺有意思的一道题目，重点在于判断两个矩形是否重叠，并且如何计算重叠区域的面积。
 * 
 * 
 * 
+----------+
|          |    +-------------+
|          |    |             |
|          |    |             |
|          |    +-------------+
+----------+


+-----------+
|           |
|    +-------------------------+
|    |      |                  |
|    |      |                  |
|    |      |                  |
|    +-------------------------+
|           |
+-----------+

 * 情况基本上就是这两种
 *
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(A - C) * abs(B - D);
        int area2 = abs(E - G) * abs(F - H);

        // 判断是否有重叠，一共有 4 中不可能重叠的情况
        if (B >= H || E >= C || A >= G || F >= D)
            return area1 + area2;
        
        // 有重叠，需计算重叠区域。Test Case 有整数溢出的情况，需进行考虑
        long long total = (long long)area1 + (long long)area2;
        return total - (min(C, G)-max(A,E)) * (min(H, D) - max(B, F)); 
    }
};
