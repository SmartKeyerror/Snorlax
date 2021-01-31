
#include <cstdint>
#include <cmath>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int start = 31;
        uint32_t res = 0;
        while (n) {
            int bit = n & 1;
            if (bit) res += bit * pow(2, start);
            n >> 1;
            start --;
        }
        return res;
    }
};
