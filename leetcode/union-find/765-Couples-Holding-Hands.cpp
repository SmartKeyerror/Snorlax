
#include <vector>

using namespace std;

/*
 * 给定了一个包含 n 个数的数组，其值为 0...n-1，且 n 为偶数。要求通过交换数组中的两个元素，使得所有应该配对的情侣正确配对，并返回最小交换次数。
 * 
 * 配对的条件其实就是 (0, 1), (2, 3), (4, 5)，也就是一个偶数和比它大 1 的奇数进行配对。
 * 
 * 尝试了一下，贪心算法是可行的，但是不知道怎么证明（贪心算法常见...）。贪心的思路非常简单: 每一次交换都让一对没有配对的情侣配对。
 * 
 * 以 [3, 4, 0, 5, 1, 2] 为例，我们从数组的第一个元素开始。第一对是 [3, 4]，3 应该和 2 配对，不是 4，那么我们就在后面数组中去找到 2，然后和 4 进行交换。
 * 
 * 得到 [3, 2, 0, 5, 1, 4]。再看第二对，为 [0, 5]，同样不是正确的配对，那么我们就找 0 应该配对的那个元素，也就是 1，让它和 5 交换。
 * 
 * 得到 [3, 2, 0, 1, 5, 4]，最后一对 [5, 4] 为准确的配对，可以结束交换了。实际上对于 nums 数组来说，直到前面的 n/2 - 1 对都配对成功的话，最后一对一定是能够配对的。 
 */
class Solution {
private:
    int getAnother(int x) {
        if (x & 1) return x - 1;
        return x + 1;
    }
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int another = getAnother(row[i]);
            if (row[i+1] == another) continue;
            
            res ++;
            for (int j = i + 2; j < row.size(); j++) {
                if (row[j] == another) {
                    swap(row[i+1], j);
                    break;
                }
            }
        }
        return res;
    }
};