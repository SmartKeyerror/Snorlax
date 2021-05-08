
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), [](int a, int b) {
            return (a & 1) < (b & 1);
        });
        return A;
    }
};