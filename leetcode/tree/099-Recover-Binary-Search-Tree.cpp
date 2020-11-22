
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 方法主要有两个，但是都依赖于二叉树的中序遍历。 为什么是中序遍历? 因为一棵 BST 的中序遍历结果是有序的
 * 
 * 第一个方法就是中序遍历该树，输出成一个 vector，并拷贝一个 vector' 出来，对 vector' 进行排序，纠正错误节点，然后将排序后的结果逐一地赋值给原有的 vector 数组中的 TreeNode
 * 
 * 另外一个方法就是 double pointers，prev 指针和 current 指针，prev 指针初始化为 NULL，current 则为 root。
 * prev 指针表示当前中序遍历所在节点的前一个节点，而 current 则是当前根节点，那么根据 BST 的性质，一定有 prev->value < current->value 存在。当这个条件不成立时，我们就找到了一个错误节点
 * 遍历完整棵树，如果存在两个这样的错误节点，我们将其进行交换即可。
 */
class Solution {

private:

    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;

    void inorderTraversal(TreeNode* current) {
        
        if (!current) return;
        
        inorderTraversal(current->left);

        if (prev && prev->val > current->val) {
            // 此时我们已经找到了一个错误节点，但是它是第一个，还是第二个?

            // 如果 first 指针没有被赋值过，就说明它是第一个错误节点
            if (first == nullptr)
                first = prev;
            
            // second 被赋值为当前节点的原因在于，对于第二个错误的节点而言，不一定是 prev 节点，还有可能是根节点，所以得一路往上找，可参考题目中的 Example 2
            second = current;
        }

        prev = current;

        inorderTraversal(current->right);
    }

public:
    void recoverTree(TreeNode* root) {        
        inorderTraversal(root);
        swap(first->val, second->val);
        return;
    }
};
