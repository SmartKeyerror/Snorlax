

/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 * 
 *      5
 *     / \
 *    2   6
 *   / \   \
 *  1   3   8
 * 
 * 该 BST 的后序遍历结果为 [1, 3, 2, 8, 6, 5]
 * 
 * 后序遍历的定义: left-right-root，而对于一棵 BST 而言，有 left < root < right 恒成立 （这里不考虑等于）
 * 
 * 那么也就是说，postorder 数组的最后一个节点必然是 root 节点，记为 last。
 * 
 * 那么如果 postorder 是正确的，那么必然可以找到一个分界点 K，使得 [0, K - 1] 的值均小于 last，使得 [K, last - 1] 的值均大于 last。
 * 
 * 然后对这个过程递归下去就可以得到答案。
 */

#include <vector>

using namespace std;

// 时间复杂度 O(n^2)，空间复杂度为 O(n)
class Solution {
private:

    // 验证 postorder 这个后序遍历数组的 [left, right] 区间是否满足二叉搜索树的条件
    bool dfs(const vector<int>& postorder, int left, int right) {

        // 此时只有一个元素，那么必然为 true
        if (left >= right) return true;

        // 根节点一定是最后一个
        int root = postorder[right];

        int k = left;       // 寻找第一个大于 root 的元素
        while (k < right && postorder[k] < root) k ++;

        // 验证右子树是否正确，也就是 [K, right - 1] 的值是否均大于 root
        for (int i = k; i < right; i++) {
            if (postorder[i] < root) return false;
        }

        // 递归的验证左子树和右子树
        return dfs(postorder, left, k-1) && dfs(postorder, k, right - 1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size() - 1);
    }
};