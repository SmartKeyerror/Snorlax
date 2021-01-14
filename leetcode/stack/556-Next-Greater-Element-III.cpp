
#include <string>
#include <vector>

using namespace std;

/*
 * 虽然是叫 Next Greater Element，但是我觉得这道题和单调栈一点儿关系都没有
 * 
 * 假设 n = 1342，那么距离 n 最近的、由这 4 个数字组成的 int 为 1423，我们可以认为这是在求 Next Permutation 的一个问题，即下一个排列。
 * 
 * 以 “1234” 为例，其全部排列为 “1234”，“1243”，“1324”，“1342”，“1423”，“1432”，......
 * 
 * 而 "1342" 的下一个排列就是 "1423", 也就是我们需要的答案。可参考 31.Next Permutation 问题。
 */
class Solution {
private:
    vector<int> intToVector(int n) {
        vector<int> res;
        while (n) {
            res.push_back(n % 10);
            n = n / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i+1] > nums[i]) {
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }

    int vectorToInt(vector<int>& nums) {
        long nbr = 0, count = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            nbr += nums[i] * count;
            count *= 10;
        }
        return nbr > INT_MAX ? 0 : nbr;
    }
public:
    int nextGreaterElement(int n) {
        vector<int> integers = intToVector(n);
        nextPermutation(integers);
        int res = vectorToInt(integers);

        return res > n ? res : -1;
    }
};