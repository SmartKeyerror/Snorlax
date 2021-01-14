
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {

        // 维护一个阶乘的缓存，避免后续的重复计算
        vector<int> fac(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i-1] * i;
        
        // nums 备选数组，也就是 1,2,3,4,5...
        vector<char> nums(n + 1);
        for (int i = 0; i < n; i++)
            nums[i] = i + 1 + '0';
        
        k --;
        string result = "";

        for (int i = 1; i <= n; i++) {
            int j = k / fac[n-i];
            k %= fac[n-i];
            result += nums[j];
            nums.erase(nums.begin() + j);
        }
        return result;
    }
};