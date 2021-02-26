
#include <vector>
#include <string>

using namespace std;


/*
 * 没什么特别的地方，遍历 + 判断即可
 * 
 * 2/3、4/6、8/12 等化简以后其实是一个数，所以我们需要求出分子与分母的最大公约数（Greatest Common Divisor）
 * 
 * 若最大公约数不为 1 的话，说明还能继续化简，此时我们不应该将当前分子分母加入结果之中。
 */
class Solution {
public:

    // 辗转相除法
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> result;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) != 1) continue;
                result.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return result;
    }
};