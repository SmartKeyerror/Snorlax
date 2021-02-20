
#include <vector>

using namespace std;


class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return;

        prefixSum = vector<int>(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return prefixSum[j];
        return prefixSum[j] - prefixSum[i - 1];
    }
};