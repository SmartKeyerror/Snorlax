
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 有序 numbers 数组中的 Two Sum 问题。双指针处理，初始化时 left = 0, right = numbers.size() - 1。
 * 
 * 若 numbers[left] + numbers[right] == target， 直接返回
 * 
 * 若 numbers[left] + numbers[right] > target，说明我们此时的数字太大了，所以让右边儿的指针往左移动，即 right --
 * 
 * 否则，说明我们此时的数字太小了，所以让左边儿的指针往右移动，即 left ++
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) break;
            else if (numbers[left] + numbers[right] > target) right --;
            else left ++;
        }
        return {left + 1, right + 1};
    }
};