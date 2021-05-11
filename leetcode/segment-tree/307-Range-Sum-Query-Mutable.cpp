#include <vector>

using namespace std;


class NumArray {
private:
    vector<int> tree;
    vector<int> nums;

    int getLeftChild(int index) {return 2 * index + 1;}

    int getRightChild(int index) {return 2 * index + 2;}
    
    // 线段树的构建过程本质上就是一个二叉树的后序遍历过程，先计算出左右子树的 sum 和，然后再计算根节点的和。
    void buildSementTree(int treeIndex, int left, int right) {
        if (left == right) {
            tree[treeIndex] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        int leftChild = getLeftChild(treeIndex), rightChild = getRightChild(treeIndex);

        buildSementTree(leftChild, left, mid);
        buildSementTree(rightChild, mid + 1, right);

        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }

    // 线段树的查询同样是一个后序遍历的过程，先查出左右子树的 sum 和，然后加起来
    // 函数语义: 在 treeIndex 为根节点，并且该节点于线段树的范围为 [left, right]，查询区间为 [queryL, queryR]
    int query(int treeIndex, int left, int right, int queryL, int queryR) {

        // 到叶子节点即可返回
        if (left == queryL && right == queryR)
            return tree[treeIndex];
        
        int mid = left + (right - left) / 2;
        int leftChild = getLeftChild(treeIndex), rightChild = getRightChild(treeIndex);

        if (queryR < mid + 1)       // 此时只需要查询左子树即可
            return query(leftChild, left, mid, queryL, queryR);
        else if (queryL > mid)      // 此时只需要查询右子树即可
            return query(rightChild, mid + 1, right, queryL, queryR);
        
        // 除此以外，我们需要分别查询左右子树，然后将其返回值聚合起来
        int leftResult = query(leftChild, left, mid, queryL, mid);
        int rightResult = query(rightChild, mid + 1, right, mid + 1, queryR);

        return leftResult + rightResult;
    }

    // 线段树的更新还是一个后序遍历的过程。首先更新叶子节点，然后再逐层地往上进行更新。
    void update(int treeIndex, int left, int right, int updateIndex, int updateValue) {
        if (left == right) {
            nums[updateIndex] = updateValue;
            tree[treeIndex] = updateValue;
            return;
        }

        int mid = left + (right - left) / 2;
        int leftChild = getLeftChild(treeIndex), rightChild = getRightChild(treeIndex);

        if (updateIndex <= mid)     // 更新左子树
            update(leftChild, left, mid, updateIndex, updateValue);
        else
            update(rightChild, mid + 1, right, updateIndex, updateValue);
        
        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }

public:
    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size(), treeSize = 0;

        // n 恰好是 2 的 k 次幂，此时我们只需要开 2n 的空间即可
        if (!(n & (n-1))) treeSize = 2 * n;
        else treeSize = 4 * n;

        tree = vector<int>(treeSize, 0);

        buildSementTree(0, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        update(0, 0, nums.size() - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, nums.size() - 1, left, right);
    }
};