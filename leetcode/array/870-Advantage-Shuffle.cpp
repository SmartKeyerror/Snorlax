
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
 * 一道比较典型的贪婪问题。
 * 
 * 对于 A[i] 来说，我们应该选择比 B[i] 要大的最小。
 * 
 * 如果没有比 B[i] 还要大的最小值的话，那我们就选当前 A 中的最小值，丢进去占一个位置，滥竽充数用的。
 * 
 * 对于 A 而言，我们需要不断地寻找比 B[i] 大的最小值，以及 A[i] 中的最小值，并且还需要删除掉那些已经匹配过的值。
 *
 */
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result;
        int n = A.size();

        if (n == 0) return result;

        sort(A.begin(), A.end());

        for (int i = 0; i < n; i++) {
            int nbrb = B[i];
            auto it = upper_bound(A.begin(), A.end(), nbrb);
            if (it != A.end()) {
                result.push_back(*it);
                A.erase(it);
            }
            else {
                result.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return result;
    }
};