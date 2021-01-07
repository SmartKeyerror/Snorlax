
#include <numeric>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0 || x + y >= z && z % __gcd(x, y) == 0);
    }
};
