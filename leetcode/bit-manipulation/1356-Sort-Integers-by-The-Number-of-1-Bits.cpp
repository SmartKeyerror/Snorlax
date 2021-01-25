
#include <vector>

using namespace std;


class Solution {
private:
    static int get1Bits(int num) {
        int res = 0;
        while (num) {
            if (num & 1) res ++;
            num = num >> 1;
        }
        return res;
    }
    static bool compare(int a, int b) {
        int resa = get1Bits(a), resb = get1Bits(b);
        if (resa == resb) return a < b;
        return resa < resb;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
