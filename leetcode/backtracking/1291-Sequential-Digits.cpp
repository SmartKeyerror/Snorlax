
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> result;

    void backtracking(int low, int high, int number) {
        if (number > high) return;

        if (number >= low && number <= high) result.push_back(number);

        for (int i = 0; i < 10; i++) {
            if (i - number % 10 == 1)
                backtracking(low, high, number * 10 + i);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i < 10; i++)
            backtracking(low, high, i);
        sort(result.begin(), result.end());
        return result;
    }
};