
#include <vector>

using namespace std;

/*
 * 这道题和 1720 号问题非常类似，只不过这道题中并没有给出 first number，而是给出了一些其他的条件。
 * 
 * 以 [2, 1, 3, 5, 4] 为例，encoded 应为: [3, 2, 6, 1]
 */
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int firstNum = 0, cumulativeXor = 0;
        for (int i = 0; i < n - 1; i++) {
            cumulativeXor = cumulativeXor ^ encoded[i];
            firstNum = firstNum ^ cumulativeXor;
        }
        
        for (int i = 1; i <= n; i++) firstNum = firstNum ^ i;

        vector<int> result;
        result.push_back(firstNum);
        int prev = firstNum;
        
        for (int i = 0; i < n - 1; i++) {
            int tmp = prev ^ encoded[i];
            result.push_back(tmp);
            prev = tmp;
        }
        
        return result;
    }
};