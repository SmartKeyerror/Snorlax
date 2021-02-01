
#include <vector>

using namespace std;


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0, n = arr.size();
        vector<int> prefixXOR(n, 0);

        prefixXOR[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefixXOR[i] = prefixXOR[i-1] ^ arr[i];
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if ((prefixXOR[i] ^ prefixXOR[j] ^ arr[i]) == 0)
                    res += j - i;
            }
        }
        return res;
    }
};