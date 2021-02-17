
#include <vector>

using namespace std;

/*
 * 将偶数排在前面，奇数排在后面
 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;

        for (int i = 0; i < A.size(); i++) {
            if ((A[i] & 1) == 0) result.push_back(A[i]);
        }

        for (int i = 0; i < A.size(); i++) {
            if (A[i] & 1) result.push_back(A[i]);
        }

        return result;
    }
};