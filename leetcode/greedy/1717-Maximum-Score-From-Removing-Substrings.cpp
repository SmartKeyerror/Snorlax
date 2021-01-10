
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if(x < y)
            swap(x, y), reverse(s.begin(), s.end());

        int a = 0, b = 0, ans = 0;

        for(char c : s) {
            if(c == 'a') a++;
            else if(c == 'b') {
                if(a) ans += x, a--;
                else b++;
            }
            else ans += min(a,b)*y, a = b = 0;
        }
        return ans + min(a,b)*y;
    }
};
