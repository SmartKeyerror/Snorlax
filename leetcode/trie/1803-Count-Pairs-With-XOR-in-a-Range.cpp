#include <vector>

using namespace std;


struct TrieNode {
    // 因为 bit 位要么是 0，要么是 1，所以我们可以使用一个数组来表示
    TrieNode *child[2];

    // 记录经过了该节点共有多少个 number
    int count;

    TrieNode() : count(0) {
        child[0] = child[1] = nullptr;
    }
};


// 将 int 类型的 number 插入至 Trie
void insertTrie(TrieNode *root, int N) {
    for (int i = 31; i >= 0; i--) {
        bool x = (N) & (1 << i);

        if(!root->child[x]) {
            root->child[x] = new TrieNode();
        }

        root->child[x]->count ++;
        root= root->child[x];
    }
}
 
/*
 * 计算当前 Trie 数中，与 N 进行异或操作的结果小于 K 的数量
 */
int countSmaller(TrieNode * root, int N, int K){
     
    int countPairs = 0;
     
    for (int i = 31; i >= 0 && root; i--) {
                                          
        bool x = N & (1 << i);
        bool y = K & (1 << i);
        
        // 如果 K 的第 i 位为 1 的话，那么按照 XOR 的性质，1 XOR 1 = 0, 1 XOR 0 = 1
        // 那么我们需要做的事情就是尽可能的让异或结果为 0， 这样才能使得最终结果更小，而不是更大
        if (y) {
            
            // 如果 N 的第 i 位为 1 的话，那么我们一定能够保证，包含当前 TrieNode 节点的所有路径的元素与 N 
            // 异或均小于 K，因为此时第 i 位的异或结果将是 0，而 K 的第 i 位为 1
            if(root->child[x]) {
                countPairs += root->child[x]->count;
            }

            root = root->child[1 - x];
        }
        else {
            root = root->child[x];
        }
    }
    return countPairs;
}
 
int countSmallerPairs(vector<int>& array, int K) {
    TrieNode *root = new TrieNode();
    int countPairs = 0;
     
    for(int i = 0; i < array.size(); i++){    
        countPairs += countSmaller(root, array[i], K);
        insertTrie(root, array[i]);
    }
    return countPairs;
}



class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return countSmallerPairs(nums, high + 1) - countSmallerPairs(nums, low);
    }
};
