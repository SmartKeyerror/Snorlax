
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;

class Solution {
private:

    vector<int> memory;

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

    int findMaxMultiplication(int n) {

        if (n == 1)
            return 1;

        if (memory[n] != -1)
            return memory[n];

        int res = -1;
        for (int i = 1; i < n; i++) {
            res = max3(res, i * (n-i), i * findMaxMultiplication(n-i));
        }
        memory[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        memory = vector<int>(n+1, -1);
        return findMaxMultiplication(n);
    }

    int integerBreakWithDP(int n) {
        memory = vector<int>(n+1, -1);

        memory[1] = 1;

        for (int i = 1; i <= n; i++) {
            // 求解 memory[i]
            for (int j = 1; j <= i -1; j++) {
                memory[i] = max3(memory[i], j*(i-j), j*memory[i-j]);
            }
        }

        return memory[n];
    }
};
