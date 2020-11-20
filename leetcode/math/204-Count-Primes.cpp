
#include <vector>

using namespace std;

/*
 * 该题被分类在 hash-table 的标签下，但是我认为它算是一个 DP 问题，或者说，递推问题
 * 问题描述很简单，求小于 n 的质数数量
 * 
 * 首先我们来看下什么是质数，除了1和该数自身外，无法被其他自然数整除的数，例如 2, 3, 5, 7 等等
 * 
 * 对于一个质数而言，的确没有递推公式，但是对于非质数而言却是有的。
 *  - 对于质数 2，2 * 2, 2 * 3, 2 * 4, 2 * 5, 2 * n，这些数一定不是质数
 *  - 对于质数 3，3 * 2, 3 * 3, 3 * 4, 3 * 5, 3 * n，这些数也一定不是质数
 *  - 对于质数 5，5 * 2, 5 * 3, 5 * 4, 5 * 5, 5 * n，这些数同样不是质数
 * 
 * 所以，对于 countPrimes(n) 来说，我们只需要递推出小于 n 的所有数，再从其中筛选出质数的数量即可
 * 
 * 另外一个需要注意的问题就是，如果我们要写一个 isPrime 判断一个数是否是质数的函数，该如何书写?
 * 
    bool isPrime(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
 * 
 * 这么写绝对没有问题，但是效率不高。原因在于 i 不必遍历到 n, 只需要遍历到 sqrt(n) 即可
 * 
 * 8 = 2 * 4
 * 8 = sqrt(8) * sqrt(8)
 * 8 = 4 * 2
 * 
 * sqrt(n) 就是一个“中点”，因数的乘积过了这个中点之后就开始逆转顺序。所以我们只需要将遍历终止条件改为 i * i < n 即可
 * 
 */
class Solution {
public:
    int countPrimes(int n) {

        vector<bool> memory(n, true);

        for (int i = 2; i * i < n; i++) {
            if (memory[i]) {
                for (int j = i * i; j < n; j += i) {
                    memory[j] = false;
                }
            }
        }

        int result = 0;

        for (int i = 2; i < n; i++)
            if (memory[i]) 
                result ++;
        
        return result;
    }
};
