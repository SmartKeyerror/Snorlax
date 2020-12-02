
#include <unordered_set>

using namespace std;

class Solution {
private:
    int sumOfDigitsSquares(int n) {
        // 计算整型 n 各个数字的平方和
        int res = 0, value = n;
        while (value) {
            res += (value % 10) * (value % 10);
            value  = value / 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> pool;
        int current = sumOfDigitsSquares(n);
        pool.insert(current);
        while (true) {
            current = sumOfDigitsSquares(current);
            if (current == 1) return true;
            else if (pool.find(current) != pool.end()) return false;
            else pool.insert(current);
        }
    }
};
