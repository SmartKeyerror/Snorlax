
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> intPair;

struct compare {
    bool operator () (intPair &a, intPair &b) {
        return a.first + a.second < b.first + b.second;
    }
};

/*
 * 将所有的组合丢到大小为 k 的小堆中即可。
 */
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<intPair, vector<intPair>, compare> heap;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (heap.size() == k) {
                    if (nums1[i] + nums2[j] < heap.top().first + heap.top().second) {
                        heap.pop();
                        heap.push({nums1[i], nums2[j]});
                    }
                } else 
                    heap.push({nums1[i], nums2[j]});
            }
        }

        vector<vector<int>> result;
        while (!heap.empty()) {
            result.push_back({heap.top().first, heap.top().second});
            heap.pop();
        }
        return result;
    }
};