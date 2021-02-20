
#include <vector>

using namespace std;

/*
 * Mountain Array 问题，只需要找到拐点即可。
 */
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        if (n <= 2) return false;

        int peak = 0;

        // 找到峰顶
        while (peak < n - 1 && arr[peak] < arr[peak + 1]) peak ++;
        
        if (peak == 0 || peak == n - 1) return false;

        while (peak < n - 1 && arr[peak] > arr[peak + 1]) peak ++;

        return peak == n - 1;
    }
};