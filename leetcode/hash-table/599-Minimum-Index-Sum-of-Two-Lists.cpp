#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> pool1;
        for (int i = 0; i < list1.size(); i++)
            pool1[list1[i]] = i;
        
        int sum = INT_MAX;
        vector<string> result;

        for (int i = 0; i < list2.size(); i++) {
            if (pool1.count(list2[i])) {
                if (i + pool1[list2[i]] < sum) {
                    result.clear();
                    result.push_back(list2[i]);
                    sum = i + pool1[list2[i]];
                } else if (i + pool1[list2[i]] == sum)
                    result.push_back(list2[i]);
            }
        }
        return result;
    }
};