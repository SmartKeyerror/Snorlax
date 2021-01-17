
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        unordered_map<int, vector<pair<int, int>>> record;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                record[product].push_back({i, j});
            }
        }

        for (auto item : record) {
            int nbr = item.second.size();
            if (nbr == 2) res += 8;
            else res += (nbr * (nbr - 1) / 2) * 8;
        }

        return res;
    }
};
