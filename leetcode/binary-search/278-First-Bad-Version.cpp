

// 278. First Bad Version，其实就是找到元素的插入位置，并且元素是唯一的

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // mid 为 bas version，需向左寻找
            if (isBadVersion(mid)) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};
