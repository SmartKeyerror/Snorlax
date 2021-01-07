

class Solution {
private:
    int recusive(int n) {
        if (n == 1) return 0;

        if (n % 2 == 0) return n / 2 + recusive(n / 2);

        else return (n - 1) / 2 + recusive((n - 1) / 2 + 1);
    }
public:
    int numberOfMatches(int n) {
        return recusive(n);
    }
};
