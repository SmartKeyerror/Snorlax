
#include <queue>
#include <vector>

using namespace std;


/*
 * We have a collection of stones, each stone has a positive integer weight.
 * 
 * Each turn, we choose the two heaviest stones and smash them together.  
 * Suppose the stones have weights x and y with x <= y.  The result of this smash is:
 * 
 * - If x == y, both stones are totally destroyed;
 * - If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
 * 
 * At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
 * 
 * 因为每次都需要取最大的两个石头，所以使用大堆顶，并且在进行计算之后还需要放回剩余的“残留石块”，所以我把这种问题归类为“使用堆的放回取样”
 * 
 * 1792. Maximum Average Pass Ratio，https://leetcode.com/problems/maximum-average-pass-ratio/
 * 
 * 上面的这道问题也可以使用相同的思路来完成，每次取一个最值进行处理，然后放回取样池，接着再取最值进行处理，直到达到了目标条件。
 */

// 时间复杂度 O(nlogn)，空间复杂度 O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // 这一步其实可以使用 make_heap 以 O(n) 的时间复杂度完成，不过影响不是很大，
        // 并且其 API 需要使用原 vector 进行操作，不是很直观
        priority_queue<int> stonePool;
        for (int stone : stones) {
            stonePool.push(stone);
        }

        // 题目要求我们返回最后一块石头，所以目标条件就是 stonePool.size() 小于或者等于 1
        while (stonePool.size() > 1) {
            int first = stonePool.top();
            stonePool.pop();

            int second = stonePool.top();
            stonePool.pop();

            // both stones are totally destroyed
            if (first == second) continue;

            // the stone of weight y has new weight y-x.
            stonePool.push(first - second);
        }

        return stonePool.size() == 0 ? 0 : stonePool.top();
    }
};