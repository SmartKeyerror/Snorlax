#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<string> result;
    vector<bool> visited;

    string genAns(vector<int> selected) {
        string s;
        for (int nbr: selected) {
            s += to_string(nbr) + ".";
        }
        s.pop_back();
        return s;
    }

    void backtracking(string &s, int index, vector<int> &selected) {

        if (selected.size() == 4 && index == s.size()) {
            result.push_back(genAns(selected));
            return;
        }

        for (int i = index; i < s.size(); i++) {

            if (selected.size() > 4) break;

            string sub = s.substr(index, i - index + 1);

            if (stoi(sub) > 255 || sub.size() > 1 && sub[0] == '0') break;

            selected.push_back(stoi(sub));

            backtracking(s, i + 1, selected);

            selected.pop_back();
        }
        return;
    }

public:
    vector<string> restoreIpAddresses(string s) {

        if (s.size() > 3 * 4) 
            return result;

        vector<int> selected;

        backtracking(s, 0, selected);

        return result;
    }
};
