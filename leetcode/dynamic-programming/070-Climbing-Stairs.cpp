
#include <vector>

using namespace std;

/*
 * 题目虽然简单，但是却是一类动态规划问题的最基础问题
 */
class Solution {

private:

    // 自顶向下的递归实现
    int recursiveSolution(int n) {
        vector<int> memory = vector<int>(n + 1, -1);

        return recursive(n, memory);
    }

    int recursive(int n, vector<int> &memory) {
        if (n <= 2)
            return n;
        
        if (memory[n] != -1)
            return memory[n];
        
        memory[n] = recursive(n-1, memory) + recursive(n-2, memory);
        return memory[n];
    }

    // 自底向上的递推实现
    int iterationSolution(int n) {

        if (n <= 2)
            return n;

        vector<int> memory = vector<int>(n + 1, 0);

        memory[1] = 1, memory[2] = 2;

        for (int i = 3; i <= n; i++)
            memory[i] = memory[i-1] + memory[i-2];
        
        return memory[n];
    }

public:
    int climbStairs(int n) {
        return iterationSolution(n);
    }
};