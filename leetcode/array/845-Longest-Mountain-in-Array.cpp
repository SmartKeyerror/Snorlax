
#include <vector>

using namespace std;

/*
 * 寻找数组中最长的 “⛰”，并返回该 ⛰ 的长度。
 * 
 * 有点儿向寻找最长回文串的一般解法，回文串根据中心对称，而对于一座 ⛰ 而言，也是关于中心对称的。也就是从山峰出发，不管是向左边儿走还是向右边儿都是递减的。
 * 
 * 那么我们就可以让数组中每一个元素作为山峰，然后向左、右遍历，来寻找以当前元素为峰值的 ⛰ 的长度。
 */
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int result = 0;

        for (int i = 1; i < arr.size() - 1; i++) {
            int peak = i;
            int left = peak, right = peak;

            while (left >= 1 && arr[left-1] < arr[left])
                left --;
            
            while (right < arr.size() - 1 && arr[right] > arr[right + 1])
                right ++;
            
            if (left != right && left != peak && right != peak)
                result = max(result, right - left + 1);
        }
        return result;
    }
};