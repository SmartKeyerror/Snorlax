
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {

private:

    vector<string> result;

    vector<int> used;

    vector<string> digitsArray = {
        "",
        "",
        "abc",
        "def", 
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void permute(string &digits, int index, string &selected) {

        // 递归终止条件
        if (selected.size() == digits.size()) {
            result.push_back(selected);
            return;
        }

        int currentDigits = digits[index] - '0';
        string currentString = digitsArray[currentDigits];

        for (int i = 0; i < currentString.size(); i++) {
            // 选择
            selected.push_back(currentString[i]);

            permute(digits, index + 1, selected);

            // 撤销
            selected.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        result.clear();

        if (digits.size() == 0)
            return result;

        string selected;
        permute(digits, 0, selected);
        
        return result;
    }
};
