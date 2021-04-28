
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
private:
    // Runtime: 364 ms, faster than 27.55% of C++ online submissions for 3Sum With Multiplicity.
    int twoPointersSloution(vector<int>& arr, int target) {
        int result = 0, mod = 1e9 + 7;;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 2; i++) {
            int left = i + 1, right = arr.size() - 1;
            while (left < right) {
                if (arr[i] + arr[left] + arr[right] == target) {

                    // 此时我们需要统计 [left, right] 之间有多少个元素等于 nums[left]
                    int j = left, k = right;
                    int leftCount = 0, rightCount = 0;

                    while (j <= right && arr[j] == arr[left]) {
                        leftCount ++, j ++;
                    }

                    // 判断是不是 [2, 2, 2, 2] 这样的情况
                    if (j > right) {
                        int count = (leftCount * (leftCount - 1)) / 2;
                        result = (result + count) % mod;
                    }
                    else {
                        // 否则，我们得统计 (left, right] 之间有多少个元素等于 nums[right]
                        while (j <= k && arr[k] == arr[right]) {
                            rightCount ++, k --;
                        }

                        int count = (leftCount * rightCount) % mod;
                        result = (result + count) % mod;
                    }
                    left = j, right = k;
                }
                else if (arr[i] + arr[left] + arr[right] < target) left ++;
                else right --;
            }
        }
        return result;
    }

    // Runtime: 848 ms, faster than 17.70% of C++ online submissions for 3Sum With Multiplicity.
    int hashmapSolution(vector<int>& arr, int target) {
        unordered_map<int, int> record;
        int result = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            // hashmap 中记录的是 A + B 之和的所有可能的 frequency
            result = (result + record[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++) {
                record[arr[i] + arr[j]] ++;
            }
        }
        return result;
    }

public:
    int threeSumMulti(vector<int>& arr, int target) {
        return twoPointersSloution(arr, target);
        // return hashmapSolution(arr, target);
    }
};