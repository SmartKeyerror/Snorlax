
#include <vector>
#include <map>

using namespace std;


/*
 * Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size(), shards = n / W;

        if (n % W != 0) return false;

        map<int, int> freq;
        for (int num : hand) freq[num] ++;

        for (int i = 0; i < shards; i++) {
            auto it = *freq.begin();
            int current = it.first;
            for (int j = current; j < current + W; j++) {
                if (freq.count(j) == 0) return false;
                freq[j] --;
                if (freq[j] == 0) freq.erase(j);
            }
        }
        return true;
    }
};