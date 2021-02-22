

#include <functional>

using namespace std;


class MountainArray {
public:
    int get(int index);
    int length();
};

/*
 * 挺有意思的一道题目，在一个 Mountain Array 寻找目标值为 target 的元素，并返回其较小索引。
 * 
 * 并且，只能通过 mountainArr.get(index) 来访问 array 中的元素，也就是询问索引为 index 的元素的值是多少，并且询问次数不得超过 100。
 * 
 * 假设 mountainArr 中的值为 [1, 4, 6, 9, 12, 15, 18, 24, 36, 25, 21, 10], target = 6，来看一下我们该如何处理。
 * 
 * 首先，必须要找到 peak，也就是 ⛰ 峰的值，可以通过 Binary Search 来完成。找到 peak 之后就好办了，左边儿和右边儿分别进行 Binary Search。
 */
class Solution {
private:
    int binarySearch(int target, MountainArray &mountainArr, int left, int right, function<bool (int, int)> f) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (f(mountainArr.get(mid), target)) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) left = mid + 1;
            else right = mid;
        }

        int peak = left;

        if (mountainArr.get(peak) == target) return peak;

        if (mountainArr.get(peak) < target) return -1;

        // 先在左边儿查找
        auto leftFunc = [](int p, int q) -> bool {return p < q;};
        int leftRes = binarySearch(target, mountainArr, 0, peak - 1, leftFunc);
        if (leftRes != -1) return leftRes;

        // 然后在右边儿查找
        auto rightFunc = [](int p, int q) -> bool {return p > q;};
        int rightRes = binarySearch(target, mountainArr, peak + 1, n - 1, rightFunc);
        if (rightRes != -1) return rightRes;

        return -1;
    }
};