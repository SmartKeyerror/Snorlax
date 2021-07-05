
#include <algorithm>

using namespace std;


class Solution {
private:

    // 获取以 prefix 为前缀的数字数量，使用下一个位置减去当前位置的方式实现
    int countNum(int prefix, int n) {
        long long count = 0;

        long long current = prefix;
        long long next = prefix + 1;

        while (current <= n) {
            count += min((long long)n+1, next) - current;
            current = current * 10;
            next = next * 10;
        }
        return count;
    }
public:
    int findKthNumber(int n, int k) {
        // posi 表示当前我们在十叉树中遍历到了哪个位置，结果为 posi == k
        int posi = 1;
        int prefix = 1;

        while (posi < k) {
            int count = countNum(prefix, n);

            // 此时表示将 prefix 为前缀的所有数字都算进去都达不到 k 个，所以需要去下一个前缀中寻找
            if (posi + count <= k) {
                prefix ++;
                posi += count;
            }

            // 此时我们要的结果就在以 prefix 的子树中
            else if (posi + count > k) {
                prefix = prefix * 10;
                posi ++;
            }
        }

        return prefix;
    }
};
