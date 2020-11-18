
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
 * A[i] + B[j] + C[k] + D[l] = 0
 * 将 C[k] + D[l] 的值保存在一个 hashtable 中，双重循环遍历 A、B 进行查找
 * 由于求解的是 index，而不是数组中的元素值，所以值相同的元素需要进行重复计数，这与 18. 4Sum 是不一样的
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        // key 为 C[i] + D[i] 的和，value 为 C[i] + D[i] 之和所出现的频次
        unordered_map<int, int> hashmap;

        // 首先来准备 C、D 两个数组所有元素组合之和的哈希表
        for (int i = 0; i < C.size(); i++)
            for (int j = 0; j < D.size(); j++)
                hashmap[C[i]+D[j]] ++;                  // C++中的哈希表有默认值，所以可以直接自增。Python 可使用 defaultdict
        
        // 循环遍历 A、B数组，在 hashmap 中寻找 -(A[i]+B[i])
        int result = 0;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                if (hashmap.find(-(A[i]+B[j])) != hashmap.end())
                    result += hashmap[-(A[i]+B[j])];
        
        return result;
    }
};
