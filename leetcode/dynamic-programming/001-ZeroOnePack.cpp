/*
 * 0-1-背包问题属于背包问题中最为经典、并且也是最为基础的问题，其余的背包问题均可以通过转换成 0-1-背包问题进行求解
 * 
 * 问题描述:
 *   一共有 N 件物品，第 i 件物品的重量为 w(i)，价值为 v(i)。在总重量不超过背包承载上限 C 的情况下，能够获得的最大价值是多少？每件物品可以使用0次或者1次
 * 
 * 解决方案:
 *   1. 暴力搜索所有物品的组合，并求出最大值，平均时间复杂度为 O((2^n)*n)
 *   2. 在方案1的基础之上添加缓存，消除重复子问题。这里就需要使用一个二维数组来缓存我们的解，这是因为当我们已经使用了 n 件物品时，所剩余的容量 c 是不一样的
 *      例如， 3 件物品的重量分别为 1, 2, 3，总容量为 5。我们放入了一件物品之后，剩余的容量分别为 4, 3, 2。
 *      所以，我们需要一个 m * n 的数组，其中 m 为已使用的物品数量， n 为剩余的背包容量
 *   3. 最后一种方式就是使用动态规划的方式，自底向上的将结果递推出来。此时我们需要明确状态的定义以及状态转移方程
 * 
 *      0-1 背包问题的状态转移方程并不复杂，当我们考虑某个物品的时候，可以选择放入背包，也可以选择不放入背包中，对这两种选择的结果取较大值即可。
 *          
 *      F(i, c) = max{ F(i-1, c), V(i) + F(i-1, c-w(i)) }，
 *        - F(i-1, c) 表示不选择当前物品， 那么整个问题的规模缩小一个，并且背包总容量不变
 *        - V(i) + F(i-1, c-w(i)) 表示选择当前物品，那么此时的背包价值中就需要加上当前物品价值，并且问题规模数缩小一个、背包容量减少
 * 
 *      通俗的来讲就是，假设我们有 10 个物品，在选择第一个物品的时候，如果不放，那么还剩 9 个物品可选，背包容量不变； 如果选择了当前物品，那么背包价值 ￪，还剩 9 个物品可选，但背包容量减少
 */

#include <vector>
#include <assert.h>

using namespace std;

class ZeroOnePack {
private:

    vector<vector<int>> memory;

    // 在 [0..index] 中寻找容量为 capacity 的最优解
    int bestSolution(const vector<int> &weight, const vector<int> &value, int index, int capacity) {

        if (index < 0)
            return 0;
        
        if (capacity <= 0)
            return 0;

        if (memory[index][capacity] != -1)
            return memory[index][capacity];
        
        // 不选择当前物品
        int result = bestSolution(weight, value, index - 1, capacity);

        // 查看是否还有剩余的容量能容纳当前物品
        if (capacity >= weight[index])
            result = max(result, value[index] + bestSolution(weight, value, index - 1, capacity - weight[index]));
        
        memory[index][capacity] = result;
        
        return result;
    }

public:
    int zeroOnePackSolution(const vector<int> &weight, const vector<int> &value, int capacity) {
        assert(weight.size() == value.size() && weight.size() != 0 && capacity > 0);

        memory = vector<vector<int>>(weight.size(), vector<int>(capacity + 1, -1));

        return bestSolution(weight, value, weight.size() - 1, capacity);
    }
};
