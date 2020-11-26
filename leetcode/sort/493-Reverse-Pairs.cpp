#include <vector>

using namespace std;


class Solution {
private:

    int result = 0;
    
    void merge(vector<int> &nums, int left, int mid, int right) {
        vector<int> aux = vector<int>(right - left + 1, 0);
        for (int i = left; i <= right; i++)
            aux[i-left] = nums[i];
        
        long long res = 0;
        int i = left, j = mid + 1;

        for (int k = left; k <= right; k++) {
            if (i > mid) {
                nums[k] = aux[j-left];
                j ++;
            }
            else if (j > right) {
                nums[k] = aux[i-left];
                i ++;
            }
            else if (aux[i-left] <= aux[j-left]) {
                nums[k] = aux[i-left];
                i ++;
            }
            else {
                nums[k] = aux[j-left];
                j ++;
            }
        }
    }
    
    void mergeSort(vector<int> &nums, int left, int right) {
        if (left >= right) return ;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);         // 对左半部分进行归并排序
        mergeSort(nums, mid + 1, right);    // 对右半部分进行归并排序

        // 在合并之前确定两个子数组的逆序对
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > (long long)2 * nums[j])
                j ++;
            result += j - (mid + 1);
        }

        merge(nums, left, mid, right);
    }

public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() -1);
        return result;
    }
};
