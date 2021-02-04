
/*
 * 这道题好像没啥可以取巧的，就是将 a、b 逐位进行判断与计算。
 */
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bita = (a >> i) & 1;
            int bitb = (b >> i) & 1;
            int bitc = (c >> i) & 1;

            if (bitc == 1) {
                if (!(bita | bitb)) res ++;
            } else {
                if (bita | bitb) {
                    if (bita & bitb) res += 2;
                    else res += 1;
                }
            }
        }
        return res;
    }
};