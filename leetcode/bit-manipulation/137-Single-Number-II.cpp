
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * nums 除了特定的某个元素以外，其余的元素都重复了 3 次，并且该特定元素只出现了一次。
 * 
 */
class Solution {
private:
    int mapSolution(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (int num : nums) frequency[num] ++;
        for (int num : nums) {
            if (frequency[num] == 1) return num;
        }
        return -1;
    }
public:
    int singleNumber(vector<int>& nums) {
        return mapSolution(nums);
    }
};
