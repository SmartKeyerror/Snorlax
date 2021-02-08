
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // map 解决
    string mapSolution(string s, vector<int>& indices) {
        string result = "";
        unordered_map<int, char> map;
        for (int i = 0; i < indices.size(); i++)
            map[indices[i]] = s[i];
        for (int i = 0; i < indices.size(); i++)
            result += map[i];
        return result;
    }

    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string result(n, ' ');      // 空格初始化
        for (int i = 0; i < n; i++)
            result[indices[i]] = s[i];
        return result;
    }
};