
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 罗马数字转换成阿拉伯数字
 */
class Solution {
public:
    int romanToInt(string s) {
        
        // vector<int> arabic = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        // vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        int result = 0;
        unordered_map<string, int> record = {
            {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, 
            {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}
        };

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && record.count(s.substr(i, 2))) {
                result += record[s.substr(i, 2)];
                i ++;
            } else
                result += record[{s[i]}];
        }
        return result;
    }
};
