#include <vector>
#include <unordered_map>


using namespace std;


class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& a, vector<int>& b) {
        nums1 = vector<int>(a.begin(), a.end());
        nums2 = vector<int>(b.begin(), b.end());
        for (auto n : nums2) {
            freq[n] ++;
        }
    }
    
    void add(int index, int val) {
        int original = nums2[index];
        freq[original] --;
        freq[original + val] ++;
        nums2[index] += val;
        if (freq[original] == 0) freq.erase(original);
    }
    
    int count(int tot) {
        int res = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int target = tot - nums1[i];
            if (freq.count(target) != 0) res += freq[target];
        }
        return res;
    }
};