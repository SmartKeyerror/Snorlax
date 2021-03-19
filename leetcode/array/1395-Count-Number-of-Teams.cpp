
#include <vector>

using namespace std;

/*
 * 因为有两种情况: rating[i] < rating[j] < rating[k] 或者是 rating[i] > rating[j] > rating[k]，
 * 
 * 因此我们仅计算 rating[i] < rating[j] < rating[k] 的数量，然后把 rating 数组 reverse 一下，再按照从小到大的排列方式计算一遍
 * 
 * 这是这种问题的一种常用技巧。
 */
class Solution {
public:

    int bruteForceSolution(vector<int>& rating) {
        int res = 0, n = rating.size();
        
        // 对每一个 i 我们都去左边儿看看有多少数字比它小，去右边儿看看有多少数字比它大
        for (int i = 1; i < n - 1; i++) {
            int left = 0, right = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) 
                    left ++;
            }
                
            for (int j = i + 1; j < n; j++) {
                if (rating[j] > rating[i]) 
                    right ++;
            }

            res += left * right;
        }
        return res;
    }

    int solution(vector<int>& rating) {
        int res = 0, n = rating.size();

        for (int i = 1; i < n - 1; i++) {
            int leftLess = 0, leftLarger = 0, rightLess = 0, rightLarger = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) 
                    leftLess ++;
                if (rating[j] > rating[i])
                    leftLarger ++;
            }
                
            for (int j = i + 1; j < n; j++) {
                if (rating[j] > rating[i]) 
                    rightLarger ++;
                if (rating[j] < rating[i])
                    rightLess ++;
            }

            res += leftLess * rightLarger + leftLarger * rightLess;
        }
        return res;
    }

    int numTeams(vector<int>& rating) {
        // int r1 = bruteForceSolution(rating);
        // reverse(rating.begin(), rating.end());
        // int r2 = bruteForceSolution(rating);
        // return r1 + r2;

        return solution(rating);
    }
};