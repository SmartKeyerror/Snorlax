

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int result = 0;

        unordered_map<string, int> record = {
            {"type", 0}, {"color", 1}, {"name", 2}
        };

        int posi = record[ruleKey];

        for (int i = 0; i < items.size(); i++) {
            if (items[i][posi] == ruleValue) result ++;
        }

        return result;
    }
};