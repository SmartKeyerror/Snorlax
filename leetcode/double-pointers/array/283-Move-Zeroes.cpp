
#include <vector>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nextPosi = 0;                           // 使用 nextPosi 指针来保存下一个非零元素需要移动的位置，初始值为0

        for (int i = 0; i < nums.size(); i++) {     // 指针 i 用于遍历整个数组来找到零元素和非零元素，非零元素则需要移动至 nextPosi 位置中
            if (nums[i]) {
                nums[nextPosi] = nums[i];
                nextPosi++;
            }
        }

        for (int j = nextPosi; j < nums.size(); j++)
            nums[j] = 0;
    }

    void moveZeroesOptimization(vector<int>& nums) {
        int nextPosi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i != nextPosi)
                    swap(nums[i], nums[nextPosi]);
                nextPosi ++;
            }
        }
    }
};