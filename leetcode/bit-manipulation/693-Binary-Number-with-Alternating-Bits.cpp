


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;

        while (n) {
            int current = n & 1;
            n = n >> 1;
            if (prev != -1 && prev == current) 
                return false;
            prev = current; 
        }
        return true;
    }
};