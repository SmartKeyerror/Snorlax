

#include <vector>

using namespace std;

/*
 * 题目保证了⛰ 峰一定存在，并且 arr 就是一个 ⛰，所以直接遍历即可。
 * 
 * 此外，我们还可以使用二分搜索来完成，核心就在于比较 mid 和 mid + 1 这两个值之间的大小关系。
 */
class Solution {
public:
    // 12 ms
    int simpleSolution(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i+1]) return i;
        }
        return -1;
    }

    // 4 ms
    int binarySearchSolution(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid+1]) left = mid + 1;
            else right = mid;
        } 
        return left;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        // return simpleSolution(arr);
        return binarySearchSolution(arr);
    }
};