#include <vector>


using namespace std;

/*
 * 给定一个初始元素全部为 0，大小为 m*n 的矩阵 M 以及在 M 上的一系列更新操作。
 * 
 * 操作用二维数组表示，其中的每个操作用一个含有两个正整数 a 和 b 的数组表示，含义是将所有符合 0 <= i < a 以及 0 <= j < b 的元素 M[i][j] 的值都增加 1。
 * 
 * 在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。
 * 
 * 输入: 
 * m = 3, n = 3
 * operations = [[2,2],[3,3]]
 * 输出: 4
 * 解释: 
 * 初始状态, M = 
 * [[0, 0, 0],
 *  [0, 0, 0],
 *  [0, 0, 0]]
 * 
 * 执行完操作 [2,2] 后, M = 
 * [[1, 1, 0],
 *  [1, 1, 0],
 *  [0, 0, 0]]
 * 
 * 执行完操作 [3,3] 后, M = 
 * [[2, 2, 1],
 *  [2, 2, 1],
 *  [1, 1, 1]]
 * 
 * M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4
 * 
 * m 和 n 的范围是 [1,40000]。
 * a 的范围是 [1,m]，b 的范围是 [1,n]。
 * 操作数目不超过 10000。
 * 
 * 由于 m 和 n 的数值比较大，并且还是一个二维矩阵，那么直接暴力求解的话必然会超时。
 * 
 * 以 [[2,2],[3,3]] 这两个操作为例
 * 
 * 第一次操作完毕后一共有 2*2 = 4 个数受到了影响，那么此时最大整数的个数为 4
 * 
 * 第二次的操作结束以后，因为第二次的操作实际上是包含了第一次的操作的，所以结果不变，仍然为 4
 * 
 * 所以本质上是一个覆盖问题。假如说 ops = [[2, 3], [5, 2]] 的话，那么其覆盖的面积等于 min(2, 5) * min(3, 2) = 4
 */


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int s1 = m, s2 = n;

        for (const auto& op : ops) {
            s1 = min(s1, op[0]);
            s2 = min(s2, op[1]);
        }

        return s1 * s2;
    }
};