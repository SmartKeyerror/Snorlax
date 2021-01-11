

class Solution {
public:
    int hammingDistance(int x, int y) {
        int aux = x ^ y, count = 0;
        while (aux) {
            if (aux & 1) count ++;
            aux = aux >> 1;
        }
        return count;
    }
};
