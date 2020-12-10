
#include <vector>
#include <queue>

using namespace std;

/*
 * 挺有意思的一道题目，“石头大战”，“强强碰撞”， 让我想起了小学玩儿的“拔老根儿”
 * 
 * 每次取出 stones 中最强的两个石头，左右互搏，败者食尘，胜者需要付出相应的代价，从而决出最强的那个石头！
 * 
 * 欧拉欧拉欧拉，木大木大木大木大
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> candidates;
        for (int i = 0; i < stones.size(); i++)
            candidates.push(stones[i]);
        
        while (candidates.size() >= 2) {
            int champion = candidates.top();
            candidates.pop();

            int silver = candidates.top();
            candidates.pop();

            candidates.push(champion - silver);
        }

        if (!candidates.empty())
            return candidates.top();
        
        return 0;
    }
};
