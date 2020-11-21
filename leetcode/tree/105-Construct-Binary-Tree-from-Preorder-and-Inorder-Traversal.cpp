
#include <vector>
#include <unordered_map>

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
 * 从前序遍历和中序遍历的结果中恢复一个二叉树。
 * 
 * 前序遍历: root - left - right
 * 中序遍历: left - root - right
 * 
 * 从上述的遍历结果中我们就可以知道很多事情了: 
 *  1. 前序遍历结果的第一个节点一定是整棵二叉树的根节点
 *  2. 在有了根节点之后，我们就可以在中序遍历的结果中找到该根节点，假设其索引为 inorderRoot。
 *     那么 inorderRoot 之前的所有节点均为左子树节点，inorderRoot 之后的所有节点均为右子树节点。
 *  3. 如此一来我们就构建了一颗二叉树的整体框架，而后递归的调用这个过程，就能得到最终的结果
 * 
 * 同样地，对于递归算法而言，只要我们正确地表达出递归函数所蕴含的语义，就可以得到正确的答案，而不用关心具体的代码执行细节。
 * 
 * 接下来分析一下递归函数可能需要的参数:
 * - 两个数组所对应的左子树、右子树的起始索引肯定是必不可少的，如此一来就有 4 个参数: preLeft, preRight, inLeft, inRight
 * - 回顾最开始的过程，我们首先是通过前序遍历结果的第一个节点判定为根节点，然后再在中序遍历中找到该节点的。
 *   而vector 的查找效率为 O(n)，可以使用 hashmap 来优化这个查找的过程，key 为节点值，value 为对应的索引值
 * 
 * 最终，我们的递归函数参数有 preLeft, preRight, inLeft, inRight, inHashmap，以及遍历的结果
 * 
 */
class Solution {
private:
    TreeNode *traverse(vector<int>& preorder, int preLeft, int preRight, 
                       vector<int>& inorder, int inLeft, int inRight, unordered_map<int, int> &inHashmap) {
        
        if (preLeft > preRight || inLeft > inRight)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preLeft]);
        
        int inRootIndex = inHashmap[root->val];
        int leftNums = inRootIndex - inLeft;

        root->left = traverse(preorder, preLeft + 1, preLeft + leftNums, inorder, inLeft, inRootIndex - 1, inHashmap);
        root->right = traverse(preorder, preLeft + leftNums + 1, preRight, inorder, inRootIndex + 1, inRight, inHashmap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> inHashmap;

        for (int i = 0; i < inorder.size(); i++)
            inHashmap[inorder[i]] = i;
        
        return traverse(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inHashmap);
    }
};
