
#include <string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result = "";

        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 or j >= 0; i--, j--) {
            if (i >= 0) carry += a[i] - '0';
            if (j >= 0) carry += b[j] - '0';
            result = to_string(carry & 1) + result;
            carry /= 2;
        }
        return carry ? "1" + result : result;
    }
};