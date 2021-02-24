
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 滑动窗口问题，需要求子数组中 different integers 的数量正好等于 k 的所有子数组数量。
 * 
 * 其实就是让我们求数组 A 中符合的全部子数组，而不是最长的那个子数组，区分这两者非常关键，因为这直接决定着我们的滑动窗口到底该如何进行滑动的问题。
 * 
 * 这里进行一个简单的思维转换，求 “恰好 K 个” 其实是比较困难的，如果我们把题目换成求至多 K 个的话，窗口的计算就比较简单了。
 * 
 * 例如假设我们的窗口是这样的: [1, 2, 3]，在这个窗口下面，different integers 的数量至多为 K 的子数组是多少?
 */
class Solution {
public:
    int countDistinct(vector<int>& A, int K) {
        int n = A.size(), result = 0, left = 0, right = 0;
        unordered_map<int, int> window;

        while (right < n) {
            window[A[right]] ++;;
            while (left <= right && window.size() > K) {
                window[A[left]] --;
                if (window[A[left]] == 0) window.erase(A[left]);
                left ++;
            }
            result += right - left + 1;
            right ++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return countDistinct(A, K) - countDistinct(A, K - 1);
    }
};