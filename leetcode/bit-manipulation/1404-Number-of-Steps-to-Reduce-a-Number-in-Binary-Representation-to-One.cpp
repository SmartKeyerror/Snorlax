
#include <string>

using namespace std;

/*
 * 将字符串表示的一个二进制数根据一定的规则变成 1，求需要执行的步骤数量
 * 
 * 注意到 1 <= s.length <= 500，所以我们无法将其转换成 int 或者 long long 来做，除非自己写一个大数类，所以我们需要使用字符串来模拟二进制的加法和除法。
 * 
 * 这里的除法只需要除 2，所以只需要进行移位操作即可，直接将 s 的最后一位 pop_back 即可。加法的话稍微复杂一点点，需要考虑进位的问题。
 */
class Solution {
private:
    void plusOne(string &s) {
        int n = s.size();
        if (s[n-1] == '0') {
            s[n-1] = '1';
            return ;
        }

        bool findPos = false;
        s[n-1] = '0';
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1') s[i] = '0';
            else {
                s[i] = '1';
                findPos = true;
                break;
            }
        }

        if (!findPos) s = '1' + s;
    }
public:
    int numSteps(string s) {
        int res = 0;
        while (s != "1") {
            if (s[s.size() - 1] == '1') plusOne(s);
            else s.pop_back();
            res ++;
        }
        return res;
    }
};
