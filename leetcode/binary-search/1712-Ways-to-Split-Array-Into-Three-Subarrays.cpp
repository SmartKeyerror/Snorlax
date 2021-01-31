
#include <vector>
#include <numeric>

using namespace std;

/*
 * https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/999257/C%2B%2BJavaPython-O(n)-with-picture
 * 
 * votrubac 老哥写的实在是太清楚了，直接看他的描述吧...
 */
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;  long long ans = 0;
        vector<int> prefix(n);
        partial_sum(nums.begin(), nums.end(),prefix.begin());
        
        for (int i = 0; i < n - 2; i++) {
            int left = prefix[i], remain = (prefix[n - 1] - prefix[i]);
            
            if (remain < left * 2) break;
            
            int leftPtr = lower_bound(prefix.begin() + i + 1, prefix.end() - 1, left * 2) - prefix.begin();
            int rightPtr = upper_bound(prefix.begin() + i + 1, prefix.end() - 1, left + remain / 2) - prefix.begin() - 1;

            if (rightPtr - leftPtr + 1 > 0) ans += rightPtr - leftPtr + 1;
        }
        
        return ans % mod;
    }
};