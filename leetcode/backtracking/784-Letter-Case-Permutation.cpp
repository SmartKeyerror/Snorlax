
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
 * 如此清晰的易懂的代码，竟然可耻地只击败了 5.20% 的用户
 */
class Solution {

private:

    vector<string> result;

    void backtracking(string S, int index, string &selected) {
        if (selected.size() == S.size()) {
            result.push_back(selected);
            return ;
        }

        for (int i = index; i < S.size(); i++) {
            char current = S[i];

            if (current >= '0' && current <= '9') {
                selected.push_back(current);
                backtracking(S, i + 1, selected);
                selected.pop_back();
            }
            else {
                selected.push_back(tolower(current));
                backtracking(S, i + 1, selected);
                selected.pop_back();

                selected.push_back(toupper(current));
                backtracking(S, i + 1, selected);
                selected.pop_back();
            }
        }
        return ;
    }
public:
    vector<string> letterCasePermutation(string S) {
        string selected = "";

        backtracking(S, 0, selected);

        return result;
    }
};
