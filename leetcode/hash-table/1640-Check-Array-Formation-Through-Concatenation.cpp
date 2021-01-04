
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 有点儿类似于小时候玩儿的乐高拼图，反正就是将已有的积木块儿组合起来，看能不能拼凑出所需要的形状。
 */
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> pool;
        for (int i = 0; i < pieces.size(); i++) 
            pool[pieces[i][0]] = pieces[i];
        
        for (int i = 0; i < arr.size(); i++) {
            if (pool.count(arr[i]) == 0) return false;
            vector<int> piece = pool[arr[i]];
            for (int j = 0; j < piece.size(); j++) {
                if (piece[j] != arr[i]) return false;
                else i++;
            }
            i -= 1;
        }
        return true;
    }
};
