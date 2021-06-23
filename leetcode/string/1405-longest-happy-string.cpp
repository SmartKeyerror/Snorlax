

#include <vector>
#include <string>
#include <queue>

using namespace std;


/*
 * 如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。
 * 
 * 给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：
 * - s 是一个尽可能长的快乐字符串。
 * - s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
 * - s 中只含有 'a'、'b' 、'c' 三种字母。
 * 
 * 如果不存在这样的字符串 s ，请返回一个空字符串 ""。
 * 
 * 这道题目要求我们在结果中不允许出现 'aaa'、'bbb' 或者是 'ccc'，和那道重排条形码有些类似。
 * 只不过重排条形码是不允许相同的条形码相邻，这道题是不允许相同的“条形码”重复朝超过 2 次。
 * 
 * 不过原理上是一样的，贪心+堆进行解决，每次取剩余最多的字符添加到结果中。
 * 有一个特殊情况，就是当我们的结果为 "aabcc" ，a = 2, b = 2, c = 10 时，剩余最多的位 c，但是我们不能取 c，一旦取 c 的话将不满足题目要求
 * 
 * 另外一个注意点就是当我们取次多的字符时，取一个才是最优解，例如 a = 0, b = 2, c = 6，如果我们每次都取两个的话，将会得到 ccbbcc。
 * 但是如果我们对次多的字符只取一个的话，就会有 ccbccbcc，得到的字符串更长
 */
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> heap;

        heap.push({a, 'a'});
        heap.push({b, 'b'});
        heap.push({c, 'c'});

        string result = "";

        while (!heap.empty()) {
            auto current = heap.top();
            heap.pop();

            if (current.first <= 0) continue;

            // 要么在结果集中添加 1 个，要么添加两个，但是需要判断是否满足题意
            
            if (result.size() > 1 && result.back() == current.second) {
                // 此时我们就需要取次小的字符
                if (heap.empty()) break;
                auto candidate = heap.top();
                heap.pop();

                if (candidate.first <= 0) break;

                // 此时我们取一个才是最优解
                int append = 1;
                result += candidate.second;

                heap.push(current);
                if (candidate.first - append != 0)
                    heap.push({candidate.first - append, candidate.second});
            }

            // 否则，我们直接取剩余最多的那个字符进行添加
            else {
                int append = current.first >= 2 ? 2 : 1;
                for (int i = 0; i < append; i++) result += current.second;
                heap.push({current.first - append, current.second});
            }
        }
        return result;
    }
};