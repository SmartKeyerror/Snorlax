
#include <vector>
#include <numeric>

using namespace std;


/*
 * Sn=n(a1+an)/2
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        int actual = (n + 1) * n / 2;

        return actual - sum;
    }
};