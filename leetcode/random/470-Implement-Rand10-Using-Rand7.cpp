#include <random>

using namespace std;

/*
 * 使用 rand7() 实现一个 rand10()
 * 
 * 首先来看如何使用 rand2() 来实现 rand4()
 * 
 * rand2() 的范围为 [1, 2]，rand4() 的范围为 [1, 2, 3, 4]
 * 
 * 我们可以使用 (rand2() - 1) * 2 + rand2() 来实现 rand4()
 * 
 * (rand2() - 1) * 2 + rand2() = ?
 *    1                  1     = 1
 *    2                  1     = 3
 *    1                  2     = 2
 *    2                  2     = 4
 * 
 * 可以看到概率是一样的。同时，也很容易证明 (randX() - 1) * X + randX() 将会得到 [1, X*X]
 * 
 * 并且，我们也可以使用 rand4() 来实现 rand2()，只需要对 rand4() 的结果进行取余并加一即可
 * 
 * rand2() = rand4() % 2 + 1
 * 
 * 那么 rand5() 可以实现 rand2() 吗? 如果我们使用 rand5() % 2 + 1 的方式来做的话，得到结果的概率是不一样的，因为 5 无法整除 2。
 * 
 * 那么这时候我们该怎么做呢? 因为 [1, 2, 3, 4] 是可以得到 rand2() 的，而 rand5() 只是因为多了一个 5, 所以导致我们无法得到 rand2()
 * 
 * 因此，我们对其进行循环处理，如果 rand5() 的结果是 5 的话，我们就直接丢掉不用。
 * 
 * int rand2() {
 *     while(true) {
 *         int n = rand5();
 *         if (n <= 4) return n % 2 + 1; 
 *     }
 * }
 * 
 * 因此，我们首先需要扩大 rand7() 的范围，使其能表示的结果大于 10，可以使用 (rand7() - 1 ) * 7 + rand7() 得到 [1, 49] 取样
 * 
 * 因为 49 不能整除 10， 所以我们需要抛弃掉 [41, 49] 这 9 个数不用
 * 
 */

int rand7() {
    return rand() % 7 + 1;
}

class Solution {
public:
    int rand10() {
        while (true) {
            int n = (rand7() - 1) * 7 + rand7();
            if (n <= 40) return n % 10 + 1;
        }
    }
};