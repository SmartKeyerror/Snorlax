
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * 给定一个严格按照升序排序的 arr 数组，且 1 <= arr[i] <= 1000，寻找该数组中缺失的第 k 个整数。
 * 
 * arr = [2,3,4,7,11], k = 5, result = 9，本来数组应该是 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, ...]
 * 
 * 那么缺失的数组为 [1, 5, 6, 8, 9, 10, 12, 13, ...]，第 5 个缺失的数字为 9。
 */
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> pool;
        for (int num : arr) pool.insert(num);
    
        int count = 0, result = -1;
        for (int i = 1; i <= 2000; i++) {
            if (!pool.count(i)) {
                count ++;
                result = i;
                if (count == k) return result;
            }
        }
        return result;
    }
};
