#include <vector>
#include <string>

using namespace std;


class Solution {
    /*
     * 以 pcdakadsq 这一字符串为例，我们可以使用二分的策略，以当前字符为 root，向左、右开始寻找，直到遇到不同的字符为止
     * 例如 pcdakadsq，当 root 为 'k' 时，我们能获得最长回文串
     *        ←↑→
     * 不过这种方式一定要注意区分奇偶数，例如 pcdaadsq，此时最长回文字串为 "daad"，长度为偶数，此时我们要以 "aa" 为 root，也就是两个字符为 root
     * 
     * Runtime: 24 ms, faster than 86.57% of C++ online submissions for Longest Palindromic Substring.
     * Memory Usage: 7.4 MB, less than 78.95% of C++ online submissions for Longest Palindromic Substring.
     * 
     * 后面查阅资料后发现，大家都称这种算法叫“中心拓展”算法，还挺贴切的
     */
    string intuitiveSolution(string &s) {
        string result = "";
        int count = 0, n = s.size(), start = 0, end = 0;
        
        // 计算以 i 为 root 的最长回文串
        for (int i = 0; i < n; i++) {
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > count) {
                    count = right - left + 1;
                    start = left, end = right;
                }
                left --, right ++;
            }
        }

        // 计算以 i， i+1 为 root 的最长回文串
        for (int i = 0; i < n - 1; i ++) {
            int left = i , right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > count) {
                    count = right - left + 1;
                    start = left, end = right;
                }
                left --, right ++;
            }
        }
        return s.substr(start, end - start + 1);
    }


public:
    string longestPalindrome(string s) {
        return intuitiveSolution(s);
    }
};