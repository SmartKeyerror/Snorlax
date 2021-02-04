
#include <vector>

using namespace std;

/*
 * 又是一个 prefixSum 问题的变种，queries[i] = [Li, Ri] 的结果为 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]
 * 
 * 如果用 prefixSum 的眼光来看的话，相当于在求索引在 [Li, Ri] 之间子数组的和。那么我们用一个 prefixXOR 数组表示就好
 */
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n, 0);
        prefixXOR[0] = arr[0];

        for (int i = 1; i < n; i++) 
            prefixXOR[i] = prefixXOR[i-1] ^ arr[i];

        vector<int> result;
        for (auto query : queries) {
            int start = query[0], end = query[1];
            if (start == 0)
                result.push_back(prefixXOR[end]);
            else
                result.push_back(prefixXOR[end] ^ prefixXOR[start - 1]);
        }
        return result;
    }
};