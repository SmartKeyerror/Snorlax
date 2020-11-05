
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 挺有意思的一道题目， 求 n 个 括号的全部正确组合。 思路是将 '(' 和 ')' 拆开来看，分成左括号和右括号，并从左至右生成结果
 * 
 * 首先，第一个括号肯定不能是右括号，必须以左括号起步， result = "("
 * 现在就有了选择， 选择 '(' 或者是 ')'，假设我们选择了 ')'，此时 result = "()"
 * 紧接着，如果选择 ')' 的话，结果就变成了 "())"，无论如何都无法得到正确答案，此时应直接回溯
 * 
 * 那么我们如何判断当前已选择的路径是合法的呢? 由于必须使用 '(' 起手，在不断地进行选择过程中，已经选择了的 '(' 数量一定会大于等于已经选择了的 ')' 的数量
 *  例如: (()))， 已选择的 '(' 数量为 2，已选择的 ')' 数量为 3, 2 >= 3 为 false， 所以不合法
 *       ((()，  已选择的 '(' 数量为 3，已选择的 ')' 数量为 1, 3 >= 1 为 true 所以合法，可继续向下选择
 *
 * 因此，整个题目的思路就很清晰了，起始时的结果串为 "("，在 usedLeftNums >= usedRightNums 的情况下，选择 ')' 或者是 '('
 */

class Solution {
private:
    vector<string> result;

    void permute(int n, int usedLeftNums, int usedRightNums, string &selected) {

        if (usedLeftNums == usedRightNums && usedRightNums == n) {
            result.push_back(selected);
            return;
        }

        if (usedLeftNums < usedRightNums) return;

        if (usedLeftNums < n) {
            selected.push_back('(');
            permute(n, usedLeftNums + 1, usedRightNums, selected);
            selected.pop_back();
        }

        if (usedRightNums < n) {
            selected.push_back(')');
            permute(n, usedLeftNums, usedRightNums + 1, selected);
            selected.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        result.clear();

        if (n == 0)
            return result;
        
        string selected = "(";
        permute(n, 1, 0, selected);

        return result;
    }
};
