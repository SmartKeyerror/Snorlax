
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/*
 * 挺有意思的一道题目。给定字符串 s 和一个字符 c ，c 为 s 中的某一个字符。返回 s 中距离 c 最短距离的结果数组。
 * 
 * 问题可以抽象成给定一个有序的 points 数组，里面儿记录的一些坐标，然后给定一个点 x，找到离 x 最近的那个点并返回其之间的距离。
 * 
 * 如果不用 C++ 来做的话，使用二分搜索即可。C++ 可以使用 lower_bound 或者是 upper_bound 这两个底层同样使用二分搜索实现的函数完成。
 */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> result(n, 0), posi;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == c) posi.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == c) continue;
            auto it = upper_bound(posi.begin(), posi.end(), i);
            int left = INT_MAX, right = INT_MAX;

            if (it != posi.end()) left = abs(*it - i);
            if (it != posi.begin()) right = abs(*(it - 1) - i);

            result[i] = min(left, right);
            
        }
        return result;
    }
};