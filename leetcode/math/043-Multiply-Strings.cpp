
#include <string>
#include <vector>

using namespace std;


/*
 * 实现字符串乘法
 * 
 * 和字符串加法一样，模拟竖式乘法，两个数均从个位数开始，双层 for 循环遍历相乘，有进位则进行进位
 * 
 *                  2 5 6      ← i
 *                x 3 2 3      ← j
 *            ----------------
 *                    1 8      ← num1[2] * num2[2]
 *                  1 5        ← num1[1] * num2[2]
 *                0 6          ← num1[0] * num2[2]
 *                  1 2        ← num1[2] * num2[1]
 *                1 0          ← num1[1] * num2[1]
 *              0 4            ← num1[0] * num2[1]
 *                1 8          ← num1[2] * num2[0]
 *              1 5            ← num1[1] * num2[0]
 *            0 6              ← num1[0] * num2[0]
 * ----------------------------------
 *            0 8 2 6 8 8      ← result
 * 
 * 可以看到, num1[i] * num[j] 相乘的两位数结果落在 result[i+j, i+j+1] 这个范围内，那么，我们只需要去更新和维护这个区间中的进位和数值即可。
 * 
 */ 
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        vector<int> result(n1 + n2, 0);

        for (int i = n1 - 1; i >=0; i--) {
            for (int j = n2 -1; j >= 0; j--) {
                result[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                if (result[i+j+1] > 9) {
                    result[i+j] += result[i+j+1] / 10;
                    result[i+j+1] = result[i+j+1] % 10;
                }
            }
        }

        // MD，还有一个 A * 0 的 Corner Case
        while (result.size() > 2 && result[0] == 0)
            result.erase(result.begin());

        string res = "";
        for (int i = 0; i < result.size(); i ++) {
            if (i == 0 && result[i] == 0) continue;
            res += to_string(result[i]);
        }

        return res;
    }
};
