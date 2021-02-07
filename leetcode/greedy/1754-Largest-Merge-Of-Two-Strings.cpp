#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res = "";
        while (word1 != "" && word2 != "") {
            if (word1 > word2) {
                res += word1[0];
                word1 = word1.substr(1);
            } else {
                res += word2[0];
                word2 = word2.substr(1);
            }
        }
        res += word1;
        res += word2;
        return res;
    }
};