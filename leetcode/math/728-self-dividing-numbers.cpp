
#include <vector>

using namespace std;

/*
 * 自除数 是指可以被它包含的每一位数除尽的数。
 * 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 * 还有，自除数不允许包含 0 。
 * 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
 * 
 * 输入：上边界left = 1, 下边界right = 22
 * 输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 这道题除了暴力解以外，我想不出还有其它的方法了
 */

class Solution {
private:
    bool verify(int n) {
        if (n < 10) return true;
        if (n % 10 == 0) return false;

        int number = n, current;
        vector<int> digits;

        while (number) {
            current = number % 10;
            if (current == 0) return false;
            if (n % current != 0) return false;
            number /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int i = left; i <= right; i++) {
            if (verify(i)) result.push_back(i);
        }

        return result;
    }
};
