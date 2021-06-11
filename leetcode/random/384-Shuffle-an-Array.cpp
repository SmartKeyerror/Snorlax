

#include <vector>
#include <random>
#include <ctime>

using namespace std;


/*
 * Shuffle an Array，打乱打一个数组，直接使用经典的洗牌算法即可。
 */

class Solution {
private:
    vector<int> original_nums;
public:
    Solution(vector<int>& nums) : original_nums(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        vector<int> shuffled_array = original_nums;
        int n = shuffled_array.size();

        for (int i = 0; i < n; i++) {
            int r = (rand() % (n - i)) + i;
            swap(shuffled_array[i], shuffled_array[r]);
        }
        return shuffled_array;
    }
};