
#include <vector>

using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        vector<int> altitudes(gain.size() + 1, 0);

        for (int i = 0; i < gain.size(); i++) {
            altitudes[i+1] = gain[i] +  altitudes[i];
            res = max(res, altitudes[i+1]);
        }
        return res;
    }
};