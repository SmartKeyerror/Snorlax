
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] == b[1]) return a[0] > b[0];
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int sum = 0;

       for (int i = 0; i < boxTypes.size(); i++) {
           int current = min(boxTypes[i][0], truckSize);
           sum += current * boxTypes[i][1];
           truckSize  = truckSize - current;
           if (truckSize <= 0) break;
       }

       return sum;
    }
};
