
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*
 *                      root
 *            /     /    |     \      \
 *           a      e    i      o      u
 *                      /|\    / \     |
 *                     i o u  o  u     u
 * 
 * 每次进行选择时，均只能选择 ASCII 码大于等于已选择路径中最后一个元素
 * 
 *  Runtime: 340 ms, faster than 5.03% of C++ online submissions for Count Sorted Vowel Strings.
 *  _(:з」∠)_
 */
class Solution {
private:
    int result = 0;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    void permute(int &n, string &selected, int index) {
        if ( selected.size() == n ) {
            result += 1;
            return;
        }

        for (int i = index; i < vowels.size(); i++) {
            selected.push_back(vowels[i]);
            permute(n, selected, i);
            selected.pop_back();
        }
        return;
    }

    int backtracking(int n) {
        if (n == 0)
            return result;
        string selected;
        permute(n, selected, result);
        return result;
    }

    int mathSolution(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }

public:
    int countVowelStrings(int n) {
        // return backtracking(n);
        return mathSolution(n);
    }
};
