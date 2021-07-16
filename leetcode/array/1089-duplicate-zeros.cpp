
#include <vector>

using namespace std;

/*
 * 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
 * 
 * 注意：请不要在超过该数组长度的位置写入元素。
 * 
 * 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
 * 
 * 输入：[1,0,2,3,0,4,5,0]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
 * 
 * 模拟一遍即可
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
                i++;
            }
        }

        arr.resize(n);
    }
};
