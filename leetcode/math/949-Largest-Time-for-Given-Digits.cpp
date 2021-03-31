
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

    string maxValue;

    void permutation(vector<int>& arr, vector<bool>& visited, string& current) {
        if (current.size() == 4) {
            if (current.substr(0, 2) <= "23" && current.substr(2) <= "59")
                maxValue = max(maxValue, current);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (visited[i]) continue;

            if (i > 0 && arr[i] == arr[i-1] && !visited[i-1]) continue;

            visited[i] = true;
            current.push_back(arr[i] + '0');

            permutation(arr, visited, current);

            current.pop_back();
            visited[i] = false;
        }
    }
public:
    string largestTimeFromDigits(vector<int>& arr) {
        maxValue = "";

        string current = "";
        vector<bool> visited(arr.size(), false);
        
        permutation(arr, visited, current);

        if (maxValue != "")
            maxValue.insert(maxValue.begin() + 2, ':');
        
        return maxValue;
    }
};