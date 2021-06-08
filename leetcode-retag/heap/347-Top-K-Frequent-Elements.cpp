
/*
 * Given an integer array nums and an integer k, return the k most frequent elements. 
 * You may return the answer in any order.
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 取前 K 个出现频次最高的元素。
 * 
 * 题目中并没有给出 nums[i] 的取值范围，所以只能使用 hashmap 进行频次统计。
 * 如果 nums[i] 的取值范围比较小的话，可以使用 vector 来节省一些空间（需看实际数据情况）
 * 
 * 如果是超大规模数据，内存放不下怎么办? 分而治之，将数据利用 MD5() %  N 的方式分到不同的文件中，
 * 对每一个文件求 Top-K Frequency， 然后再进行合并，这个过程可并发进行。
 * 
 */

#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


// 平均时间复杂度 O(nlogK)，最坏 O(nlogn)；空间复杂度 O(n)，因为使用了 hashmap 保存频率
class Solution {
private:
    typedef pair<int, int> node;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        for (auto num : nums) freq[num] ++;

        vector<int> result;
        priority_queue<node, vector<node>, greater<node>> heap;

        for (const auto &item : freq) {
            heap.push({item.second, item.first});
            if (heap.size() > k) heap.pop();
        }

        while (!heap.empty()) {
            result.push_back(heap.top().second);
            heap.pop();
        }

        return result;
    }
};