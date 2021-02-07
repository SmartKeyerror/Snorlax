
#include <string>
#include <deque>

using namespace std;

/*
 * 在字符串的头尾进行操作，我们可以使用 deque 这一数据结构来实现。
 */
class Solution {
public:
    int minimumLength(string s) {
        deque<char> dq;
        for (auto s : s) dq.push_back(s);

        while (!dq.empty() && dq.size() != 1 && dq.front() == dq.back()) {
            char current = dq.front();
            while (!dq.empty() && dq.back() == current) dq.pop_back();
            while (!dq.empty() && dq.front() == current) dq.pop_front();
        }
        return dq.size();
    }
};