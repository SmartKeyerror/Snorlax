
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*
 * nums = [3,30,34,5,9], "9534330"
 * 首先来看 3 和 30 之间的组合关系，明显地， 3 + 30 > 30 + 3 (字符串组合形式)
 * 再来看 34 和 9，同样地 9 + 34 > 34 + 9 (字符串形式)
 * 如果我们用 Python 语言编写的话，重载 __lt__ 方法，直接返回 str(a) + str(b) > str(b) + str(a) 就可以了
 * C++ 中的字符串比较同样按照 ASCII 值进行比较，所以问题就变得相当简单了
 */
class Solution {
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {

        vector<string> record;

        for (int i = 0; i < nums.size(); i++)
            record.push_back(to_string(nums[i]));

        sort(record.begin(), record.end(), cmp);

        // 为啥 C++ 没有 join 方法呢
        string res = "";
        for (int i = 0; i < record.size(); i++) {
            res += record[i];
        }

        // input 中竟然还有 [0, 0] 这种
        return res[0] == '0' ? "0": res;
    }
};
