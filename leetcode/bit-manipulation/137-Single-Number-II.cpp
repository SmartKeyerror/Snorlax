
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * nums 除了特定的某个元素以外，其余的元素都重复了 3 次，并且该特定元素只出现了一次。
 * 
 * 在 Single Number 中，重复的数字只出现了 2 次，或者说偶数个，所以我们可以使用 XOR 运算将其“消除”，但是现在重复的数字出现了 3 次，无法直接使用 XOR 实现。
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
