

class Solution {
public:
    int numberOfSteps (int num) {
        if (num == 0) return 1;
        if (num & 1) return 1 + numberOfSteps(num - 1);
        else return 1 + numberOfSteps(num / 2);
    }
};