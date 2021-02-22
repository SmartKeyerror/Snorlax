
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int p1 = 0, n1 = word1.size(), p2 = 0, n2 = word2.size();

        while (p1 < n1 || p2 < n2) {

            if (p1 >= n1) {
                result += word2.substr(p2);
                break;
            }

            if (p2 >= n2) {
                result += word1.substr(p1);
                break;
            }
            result += word1[p1++];
            result += word2[p2++];
        }
        return result;        
    }
};