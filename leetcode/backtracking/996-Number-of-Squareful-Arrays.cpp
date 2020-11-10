
#include <math.h>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

/*
 * 不太能明白为啥这题难度为 Hard，本质上就是排列问题+重复元素选择时的减枝
 * 
 * Runtime: 4 ms, faster than 71.65% of C++ online submissions for Number of Squareful Arrays.
 */
class Solution {
    int result = 0;

    vector<bool> visited;

    bool isSqrtNbr(int n) {
        int x = sqrt(n);
        return x * x == n;
    }

    void backtracking(vector<int>& A, vector<int> &selected) {
        if (selected.size() == A.size()) {
            result++;
            return;
        }

        for (int i = 0; i < A.size(); i++) {

            // 拥有重复元素排列、组合相关的通用减枝条件，请刻在DNA中
            if (i >= 1 && A[i] == A[i-1] && !visited[i-1])
                continue;
            
            int candidate = A[i], size = selected.size();

            if (!visited[i]) {

                if (size >= 1 && !isSqrtNbr(selected[size-1] + candidate))
                    continue;
                
                visited[i] = true;
                selected.push_back(candidate);

                backtracking(A, selected);

                selected.pop_back();
                visited[i] = false;
            }
        }
        return;
    }

public:
    int numSquarefulPerms(vector<int>& A) {

        assert(A.size() != 0);

        sort(A.begin(), A.end());

        visited = vector<bool>(A.size(), false);

        vector<int> selected;
        backtracking(A, selected);

        return result;
    }
};
