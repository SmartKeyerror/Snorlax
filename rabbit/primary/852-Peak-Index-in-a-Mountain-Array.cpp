
#include <vector>

using namespace std;


// mid 在循环中定义和在外面定义在这道题中有着明显的效率差别。被注释的代码只能 beats 50%, 而未注释的代码则可以 beats 92%.
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int left = 0, right = arr.size() - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             // 题目保证了 Peak 一定存在，那么 mid 就不可能是 0 或者是 arr.size() - 1
//             if (arr[mid] < arr[mid + 1]) left = mid + 1;
//             else right = mid - 1;
//         }
//         return left;
//     }
// };


// 二分搜索
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            // 题目保证了 Peak 一定存在，那么 mid 就不可能是 0 或者是 arr.size() - 1
            if (arr[mid] < arr[mid + 1]) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
