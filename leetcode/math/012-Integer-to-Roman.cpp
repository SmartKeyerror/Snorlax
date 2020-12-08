
#include <string>
#include <vector>

using namespace std;

/*
 * 阿拉伯数字转换成罗马数字
 */
class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<int> arabic = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        for (int i = arabic.size() - 1; i >= 0; i--) {
            while (num >= arabic[i]) {
                result += roman[i];
                num -= arabic[i];
            }
        }
        return result;
    }
};
