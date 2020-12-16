
#include <vector>

using namespace std;

/*
 * 在 nums 数组中找到 nums[i]、nums[j]，使得 nums[i] ^ nums[j] 最大
 * 
 * 我们知道，^ 表示 XOR，即异或，只有当两个 bit 不相等时，操作结果才为 1。
 * 那么为了使得 XOR 的结果尽可能的大，我们就需要让 nums[i] 和 nums[j] 的 bit 位尽可能地不同
 * 
 * 例如 :
 * a = 0101 0101
 * b = 1010 1010
 * 
 * 此时 a ^ b = 255，达到 8bit 的最大值。
 * 
 * 也就是说，我们需要剖析 nums 中所有元素的 bit 组成，然后在其中找到成分差别最大的那两个元素。当然，如果成分差别相同，找最高位差别最大的。
 * 
 * 现在问题就变成了: 给定一个 nums[i]，找到和 nums[i] 成分差别最大的元素 x ，然后求 nums[i] ^ x
 * 
 * 如此一来，我们可以根据 nums 中的元素从最高位开始构造一棵前缀树，由于只有 0 和 1，所以这是一个二叉 Trie。
 * 
 * 然后，对于每一个 nums[i]，我们都尝试在 Trie 中“反着”寻找，以期望能找到成分差别最大的。
 * 
 */

struct TrieNode {
    TrieNode *next[2];
    TrieNode() {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode *current = root;
        // num 的最高位开始
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (current->next[bit] == nullptr)
                current->next[bit] = new TrieNode();
            current = current->next[bit];
        }
    }

    int maxDifferent(int num) {
        TrieNode *current = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (current->next[!bit] != nullptr) {
                res += (1 << i);
                current = current->next[!bit];
            } else
                current = current->next[bit];
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie = Trie();

        for (int i = 0; i < nums.size(); i++)
            trie.insert(nums[i]);
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result = max(result, trie.maxDifferent(nums[i]));
        
        return result;
    }
};
