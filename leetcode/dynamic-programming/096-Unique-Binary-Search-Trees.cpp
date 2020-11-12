

/*
 * 计算 1...n 这 n 个树能够组成多少棵独一无二的 BST
 * 
 * 以 n = 5 为例:
 *  - 当 1 作为 root 时，其左子树节点数为 0, 右子树节点数为 4
 *  - 当 2 作为 root 时，其左子树节点数为 1, 右子树节点数为 3
 *  - 当 3 作为 root 时，其左子树节点数为 2, 右子树节点数为 2
 *  - 当 4 作为 root 时，其左子树节点数为 3, 右子树节点数为 1
 *  - 当 5 作为 root 时，其左子树节点数为 4, 右子树节点数为 0
 * 
 * 所以 numTrees(5) = 1 as root + 2 as root + 3 as root + 4 as root + 5 as root
 * 
 * 本质上来说，假设以 k 为 root， 左子树能组成的 BST 个数为 p, 右子树能组成的 BST 个数为 q，那么总的个数就是 p * q，两者之积。
 * 所以 f(5) = f(0)*f(4) + f(1)*f(3) + f(2)*f(2) + f(3)*f(1) + f(4)*f(0)
 */
class Solution {
public:
    int numTrees(int n) {
        // 1 <= n <= 19, 所以直接整个容量为 20 的数组
        int result[20] = {0};

        // 基本问题解，空树和只有一个节点时只能组成一种 BST
        result[0] = 1, result[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                result[i] += result[j] * result[i-j-1];
            }
        }
        return result[n];
    }
};