
#include <vector>
#include <string>

using namespace std;

/*
 * 常规做法可能会涉及到很多的条件判断，所以干脆取全排列，然后从里面儿找出最大的
 * 
 * 
 */
class Solution {
private:
    void permutation(vector<int>& arr, vector<bool>& visited, vector<string>& result, string& current) {
        if (current.size() == 4) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (visited[i]) continue;

            if (i > 0 && arr[i] == arr[i-1] && !visited[i-1]) continue;

            visited[i] = true;
            current.push_back(arr[i] + '0');

            permutation(arr, visited, result, current);

            current.pop_back();
            visited[i] = false;
        }
    }
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int n = arr.size();

        vector<bool> visited(n, false);
        vector<string> result;
        string current = "";

        permutation(arr, visited, result, current);

        string currentMax = "";

        for (auto s : result) {
            if (s.substr(0, 2) <= "23" && s.substr(2) <= "59") currentMax = max(s, currentMax);
        }

        if (currentMax != "")
            currentMax.insert(currentMax.begin() + 2, ':');
        
        return currentMax;
    }
};