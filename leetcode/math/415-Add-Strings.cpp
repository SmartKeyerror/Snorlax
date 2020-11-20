
#include <string>
#include <algorithm>

using namespace std;


/*
 * 这是一道非常基础的问题，但是，越是基础的问题，就越能考察一个程序员对算法和程序的理解
 * 在 v2ex 上有一个帖子专门讨论了一下这道题的面试: https://www.v2ex.com/t/699860，帖子的回复也可以作为一个参考，虽然我并不认同楼主的一些观点，以及，评论区的部分极端言论
 * 
 * 回归正题，这道题背后的数学知识相当简单: 竖式加法，将两个数的个位、十位, 百位,... 进行对齐，进行加法运算，满 10 进 1
 * 
 * 所以，当出现 "432" + "79" 时，首先将两个字符串进行 reverse，让事情变得更加简单。reverse 之后就是 "234" + "97"，此时我们就可以从索引 0 开始计算了
 * 
 * 现在来看具体的计算过程("234" + "97"):
 *  - 首先计算 2 + 9，结果为 11，竖式加法告诉我们当某一位的结果大于等于 10 时，取余数，并进 1，也就是在竖式上打个点，作为记录，进位我们使用 carry 表示，那么此时该位计算结果为 1，carry 为 1
 *  - 然后我们计算 3 + 7，结果为 10，加上前面一位的进位，结果为 11，同样地，取余数，计算进位。加法结果为 1，carry 为 1
 *  - 再然后我们计算第三个数，"79" 没有第三个数了，我们只需要把 4 拉下来就行，再加上前面的进位 1，结果为 5
 *  - 最终，我们完成了计算，把这些结果全部扔到一个 string 中就完事儿了, 结果为 "511"
 */
class Solution {
public:
    string addStrings(string num1, string num2) {

        // 我们完全可以不用这一步，只不过会更加清晰而已
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string result = "";
        int i = 0, j = 0, carry = 0;

        while (i < num1.size() || j < num2.size()) {
            int nbr1, nbr2;
            nbr1 = i > num1.size() - 1 ? 0: num1[i] - '0';
            nbr2 = j > num2.size() - 1 ? 0: num2[j] - '0';

            int res = nbr1 + nbr2 + carry;
            int n = res % 10;
            
            result = to_string(n) + result;
            carry = res / 10;

            i ++, j ++;
        }

        return carry == 0 ? result: "1" + result;
    }
};