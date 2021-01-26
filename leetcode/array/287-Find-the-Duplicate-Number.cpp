
#include <vector>
#include <unordered_map>

using namespace std;


/*
 * 这道题感觉有点儿歧义，测试数据出来一个 [2,2,2,2,2]，
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        int ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second >= 2){
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};
