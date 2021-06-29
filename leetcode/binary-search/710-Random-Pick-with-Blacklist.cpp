#include <vector>
#include <unordered_set>
#include <random>

using namespace std;


/*
 * 给定一个包含 [0，n) 中不重复整数的黑名单 blacklist ，写一个函数从 [0, n) 中返回一个不在 blacklist 中的随机整数。
 * 
 * 对它进行优化使其尽量少调用系统方法 Math.random() 。
 * 
 * 1 <= n <= 1000000000
 * 0 <= blacklist.length < min(100000, N)
 * [0, n) 不包含 n ，详细参见 interval notation 。
 * 
 * 因为 n 的值很大，所以不能去建立一个 [0, n) 并且不包含 blacklist 中的集合。但是 blacklist 的长度最大为 10 万，可以塞到哈希集合中。
 * 
 * 所以，一个最简单的方法就是将 blacklist 塞到集合中，每次 random() 取值的时候都看看结果在不在黑名单中。
 * 
 * 然后，这方法 TLE 了，应该是 [0, n) 中只有极少部分不在 blacklist 中。
 * 
 * 这道题和 1539. Kth Missing Positive Number 其实非常类似，blacklist 中的元素就是现存的数字，而我们要找的白名单中的数字其实就是缺失的数字。
 * 
 * 先来看 1539 的二分思路: 给你一个严格升序排列的正整数数组 arr 和一个整数 k， 请你找到这个数组里第 k 个缺失的正整数。
 * 
 * 输入：arr = [2,3,4,7,11], k = 5
 * 输出：9
 * 解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
 * 
 * 对于每一个 arr 中的元素 arr[i]，该元素之前缺失的元素数量为 arr[i] - i - 1，比如当 i = 3，也就是 arr[i] = 7 时，缺失了 [1, 5, 6]，也就是 3 个元素
 * 而 arr[i] - i - 1 = 7 - 3 - 1 = 3。
 * 
 * i = 0，缺失了 arr[0] - 0 - 1 = 1 个元素
 * i = 1，缺失了 arr[1] - 1 - 1 = 1 个元素
 * i = 2，缺失了 arr[2] - 2 - 1 = 1 个元素
 * i = 3，缺失了 arr[3] - 3 - 1 = 3 个元素
 * i = 4，缺失了 arr[4] - 4 - 1 = 6 个元素
 * 
 * 假如 k = 5 的话，根据上面的表格，我们就可以知道缺失的元素必然在 arr[3] 到 arr[4] 之间，并且，缺失的元素值即为 arr[3] + 5 - 3 = 7 + 5 - 3 = 9
 * 
 * 所以，我们的最终目的就是要找到一个 i，使得 arr[i-1] - (i - 1) - 1 < k <= arr[i] - i - 1，并且此时的结果为 arr[i-1] + k - (arr[i-1] - (i - 1) - 1)
 * 
 * 最终的问题就变成了在一个有序数组中，寻找第一个大于等于给定值的元素
 */
class Solution {
private:
    int limit;
    int white;
    vector<int> blacklist;
public:
    Solution(int n, vector<int>& _blacklist) 
    : limit(n), white(n - _blacklist.size()), blacklist(_blacklist.begin(), _blacklist.end()) {
        sort(blacklist.begin(), blacklist.end());
    }
    
    int pick() {
        int k = random() % white;

        int left = 0, right = blacklist.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (blacklist[mid] - mid - 1 >= k) right = mid - 1;
            else left = mid + 1;
        }

        return k + left;
    }
};