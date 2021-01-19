
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<long long, int> genRecord(const vector<int> &nums) {
        unordered_map<long long, int> record;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                record[(long long)nums[i] * (long long)nums[j]] ++;
        return record;
    }
    int getTriplets(unordered_map<long long, int> &record, vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long nbr = (long long)nums[i] * (long long)nums[i];
            if (record.count(nbr)) res += record[nbr];
        }
        return res;
    }
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> record1 = genRecord(nums1);
        unordered_map<long long, int> record2 = genRecord(nums2);
        return getTriplets(record1, nums2) + getTriplets(record2, nums1);
    }
};