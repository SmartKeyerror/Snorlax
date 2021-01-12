
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 * Runtime: 32 ms, faster than 81.36% of C++ online submissions for Rearrange Words in a Sentence.
 * 
 * 就怎么说呢，挺丑陋的一个实现
 */
class Solution {
public:
    string arrangeWords(string& text) {
        map<int, vector<string>> record;

        int start = 0;
        transform(text.begin(), text.begin() + 1, text.begin(), ::tolower);
        
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                record[i-start].push_back(text.substr(start, i - start));
                start += i + 1;
            }
        }
        record[text.size() - start].push_back(text.substr(start, text.size() - start));

        string result = "";
        for (auto item : record) {
            for (string s : item.second) {
                result += s;
                result += " ";
            }
        }
        result.erase(result.size() - 1, 1);
        transform(result.begin(), result.begin() + 1, result.begin(), ::towupper);

        return result;
    }
};
