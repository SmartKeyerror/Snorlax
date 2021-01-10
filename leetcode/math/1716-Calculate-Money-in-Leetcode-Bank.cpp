


class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int weeks = n / 7, days = n % 7;

        res +=  weeks * 28;
        for (int i = 0; i < weeks; i++)
            res += 7 * i;

        for (int i = 1; i <= days; i++) {
            res += weeks + i;
        }

        return res;
    }
};