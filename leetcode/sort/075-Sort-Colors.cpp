
#include <vector>

using namespace std;

class Solution {

private:

    /*
     * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
     * Memory Usage: 8.7 MB, less than 75.76% of C++ online submissions for Sort Colors.
     */
    void countSortSolution(vector<int>& nums) {
        int count[3] = {0};

        // 统计 0, 1, 2 的个数
        for (int i = 0; i < nums.size(); i++)
            count[nums[i]] ++;
        
        // 统计完之后再写回原有数组
        int index = 0;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < count[j]; k++)
                nums[index++] = j;
    }

    /*
     * 借助三路快排的思想完成:
     *  array[n] => 分成3部分，前一个部分中数组元素均小于某一个 value 值，中间的部分都等于 value 值，最后一部分均大于 value 值
     * 
     *            +-----------------------------------------------------------+
     *            |                 |             |                           |
     *            |     < value     |  = value    |          > value          |
     *            |                 |             |                           |
     *            +-----------------------------------------------------------+
     * 
     * 
     */

public:
    void sortColors(vector<int>& nums) {
        countSortSolution(nums);
    }
};