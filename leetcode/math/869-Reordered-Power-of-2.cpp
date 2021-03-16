
#include <string>
#include <vector>

using namespace std;

/*
 * 1 <= N <= 10^9，也就是说 N 最多有 9 位数
 * 
 * 回溯法取全部的数字，时间复杂度也才 10！，判断 n 是否为 2 的 k 次方可使用 n & (n-1) == 0 进行判断，时间复杂度为 O(1)
 */
class Solution {
public:

    bool backtracking(string& nums, string& path, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            int n = stoi(path);
            if (n & (n-1) == 0) return true;
            return false;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (path.size() == 0 && nums[i] == '0' || visited[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            if (backtracking(nums, path, visited)) return true;
            path.pop_back();
            visited[i] = false;
        }
        return false;
    }

    bool reorderedPowerOf2(int N) {

        if (N & (N - 1) == 0) return true;

        string nums = to_string(N);
        
        sort(nums.begin(), nums.end());

        string path = "";
        vector<bool> visited(nums.size(), false);
        return backtracking(nums, path, visited);
    }
};