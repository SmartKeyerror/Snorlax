
#include <vector>
#include <queue>

using namespace std;

/*
 * 一道非常有意思的题目，给定一些砖块儿和梯子，问从第一个建筑到出发，最远能到哪一个建筑。
 * 
 * 梯子可以认为是无限长的，但是砖块儿不行，所以也就产生了选择，当从 budildings[i] 到 building[i+1]，我们到底是用梯子还是用砖块?
 * 
 * 这是一个二分选择，我们当然可以使用暴力方式，即回溯法穷举所有可能，但是 heights.length <= 10^5，远超出回溯法能够解决的数据规模。
 * 
 * 贪心可以吗? 当遇到能用砖头解决的，就用砖头解决，否则使用梯子。=> 不行
 * 
 * 从题目分析中我们可以看到，只有当砖块解决不了的时候，我们才需要使用梯子，那么也就是说我们需要知道到哪一个 building 砖块才不能够解决。
 * 
 * 之后，我们从该 building 之前的所有高度差中找到那个最大的，用梯子代替。所以，得用一个最大堆记录下高度差
 */
class Solution {
public:

    // 贪心并不是得到正确的答案，当 heights[i] - heights[i-1] 恰好等于剩余的砖块数量时，选梯子还是选砖块?
    int greedySolution(vector<int>& heights, int bricks, int ladders) {
        int i = 1;
        for (; i < heights.size(); i++) {
            if (heights[i] <= heights[i-1]) continue;

            int needBricks = heights[i] - heights[i-1];

            if (needBricks >= bricks) {
                if (ladders) ladders --;
                else return i - 1;
            } else {
                bricks -= needBricks;
            }
        }
        return i - 1;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> heap;
        int sum = 0, position = 0;

        int i = 1;
        for (; i < heights.size(); i++) {
            int dis = heights[i] - heights[i-1];

            if (dis <= 0) continue;

            heap.push(dis);
            sum += dis;

            // 此时我就需要找到最大的高度差，然后让梯子来救场
            if (sum > bricks) {
                if (ladders == 0) break;
                int current = heap.top();
                heap.pop();

                sum -= current;
                ladders --;
            }
        }

        return i - 1;
    }
};