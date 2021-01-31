#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;


class Solution {
public:
    int getNbr(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> freq;

        for (int i = lowLimit; i <= highLimit; i++) {
            freq[getNbr(i)] ++;
        }

        int res = INT_MIN;
        for (auto item : freq) {
            if (item.second > res) res = item.second;
        }
        return res;
    }
};