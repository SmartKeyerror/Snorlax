#include <vector>
#include <limits.h>

using namespace std;

/*
 * 硬币找零问题的变体，硬币找零明确地给出了哪些硬币可用，但是 Perfect Squares 却没有，得自己算
 */
class Solution {
private:
    vector<int> choices;

    void genChoices(int n) {
        for (int i = 1; i * i <= n; i++)
            choices.push_back(i * i);
    }

    /* Runtime: 400 ms, faster than 15.75% of C++ online submissions for Perfect Squares. */
    int coinChangeSolution(int n) {
        genChoices(n);
        vector<int> memory = vector<int>(n+1, INT_MAX);
        memory[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int choice: choices) {
                // 由于 choices 本身就是有序的，所以可以方便地减枝
                if (choice > i) 
                    break;

                if (memory[i-choice] != INT_MAX)
                    memory[i] = min(memory[i], memory[i-choice] + 1);
            }
        }
        return memory[n];
    }
public:
    int numSquares(int n) {
        return coinChangeSolution(n);
    }
};
