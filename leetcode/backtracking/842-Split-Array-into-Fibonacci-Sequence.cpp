
#include <vector>
#include <string>
#include <math.h>

#include <iostream>

using namespace std;

/*
 * 就怎么说呢， Python 写多了，整型越界都忘记怎么处理了...
 */
class Solution {
    
    // 即作为结果，同时也作为已选择路径
    vector<int> result;
    
    bool backtracking(string &S, int index) {

        // 递归终止条件: index >= S.size()，并且 result 至少有3个元素
        if (index == S.size() && result.size() >= 3)
            return true;

        for (int i = index; i < S.size(); i++) {

            if (S[index] == '0' and i > index)
                break;

            // C++ 中的 substr 并不像 Python 中那样...
            long considerd = stol(S.substr(index, i + 1 - index));

            if (considerd > pow(2, 31) - 1)
                break;

            int size = result.size();

            // 此时不必继续循环了，因为 considerd 会随着循环而增大
            if (size >= 2 && considerd - result[size-2] > result[size-1])
                break;

            if ( size < 2 || considerd - result[size-2] == result[size-1]) {
                result.push_back(considerd);

                if (backtracking(S, i + 1))
                    return true;
                
                // 否则，撤销选择
                result.pop_back();
            }
        }
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S) {

        result.clear();

        backtracking(S, 0);

        return result;
    }
};

