
/*
 * 题目是在是太 TM 长了，所以直接放链接:
 * - https://leetcode-cn.com/problems/maximum-average-pass-ratio/
 * - https://leetcode.com/problems/maximum-average-pass-ratio/
 * 
 * Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
 * Output: 0.78333
 * 
 * Explanation: You can assign the two extra students to the first class. 
 * The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
 * 
 * 简单的来说就是给了 classes.size() 这么多个班级，然后给出了此次考试每个班级的通过人数和班级总人数：[[1,2],[3,5],[2,2]]，表示有 3 个班级
 * 
 * - 第一个班级有 1 个人通过，共 2 人，所以通过率为 0.5
 * - 第二个班级有 3 人通过，共 5 人，故通过率为 0.6
 * - 第三个班级有 2 人通过，共 2 人，故通过率为 1.0
 * 
 * 然后我们有 2 个 ‘brilliant students’ 可以进行分配，这 2 个超凡学生什么考试都能通过，神一样的存在，然后问我们该怎么分配，使得所有班级的平均通过率最大
 * 
 * 假如 4 个班级的通过率为 A、B、C、D，那么平均通过率就是 (A+B+C+D)/4。如果 brilliant students 分配 1 个给 A 班级有最大提升，那么就给 A 班级。
 * 
 * 这个问题中局部最优解同时也是全局最优解，所以可以使用贪心的思想: 每一次我都把 brilliant students 分配给那个提升最大的班级。
 * 
 * 什么叫提升最大? 就是 (原通过人数+1)/(原总人数+1) - (原通过人数)/(原总人数) 最大的那个班级。
 * 
 * 当我们分配了一个 brilliant student 之后，数据发生了动态变化，我们需要再去取提升最大的班级，所以这是一个“放回取样”的问题
 */

#include <queue>
#include <vector>

using namespace std;


struct Compare {
    bool operator() (const pair<int, int>& A, const pair<int, int>& B) {
        double deltaA = (double)(A.first + 1)/(A.second + 1) - (double)A.first/A.second; 
        double deltaB = (double)(B.first + 1)/(B.second + 1) - (double)B.first/B.second;
        // 我们需要一个大堆顶，所以其它元素都小于堆顶
        return deltaA < deltaB; 
    }
};


// 时间复杂度 O(nlogn)，空间复杂度 O(n)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

        // 将所有的原有数据放入
        for (auto c : classes) {
            heap.push({c[0], c[1]});
        }

        while (extraStudents) {
            // 取出提升最大的那个班级
            auto most = heap.top();
            heap.pop();

            // 分配
            extraStudents --;
            most.first++, most.second++;

            // 分配完 brilliant student 之后还得放回去
            heap.push(most);
        }

        double result = 0;

        // 统计最终结果
        while (!heap.empty()) {
            auto item = heap.top();
            heap.pop();

            // 计算通过率
            result += (double)item.first / item.second;
        }

        return result / classes.size();
    }
};
