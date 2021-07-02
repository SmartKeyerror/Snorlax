
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> maps;
        for (string p : paths) {
            string currPath = "";
            string currName = "";
            int start = 0;
            int n = p.size();
            for (int i = 0; i < n; ++i) {
                if (currPath.empty()) {
                    if (p[i] == ' ') {
                        currPath = p.substr(0, i);
                        start = i+1;
                    }
                }
                else if (p[i] == '(') {
                    currName = p.substr(start, i - start);
                    start = i + 1;
                }
                else if (p[i] == ')') {
                    maps[p.substr(start, i- start)].push_back(currPath + "/" + currName);
                    start = i + 1;
                }
                else if (p[i] == ' ') {
                    ++start;
                }
            }
        }

        for (auto iter = maps.begin(); iter != maps.end(); ++iter) {
            if (iter->second.size() >= 2) {
                res.emplace_back(iter->second);
            }
        }
        return res;
    }
};
