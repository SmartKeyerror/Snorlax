
#include <string>

using namespace std;


class Solution {
public:
    string maxValueofPri(string& n, int x) {
        int s = n.size();
        for (int i = 0; i < n.size(); i++) {
            if (x > (n[i] - '0')) {
                n.insert(n.begin() + i, x + '0');
                break;
            }
        }
        if (s != n.size()) n.push_back(x + '0');
        return n;
    }

    string maxValueofNeg(string& n, int x) {
        int s = n.size();
        for (int i = 0; i < n.size() - 1; i++) {
            if ( x > (n[i] - '0') && x < (n[i+1] - '0')) {
                n.insert(n.begin() + i + 1, x + '0');
                break;
            }
        }
        if (s != n.size()) {
            if (x < (n[0] - '0')) n.insert(n.begin(), x + '0');
            else n.insert(n.end(), x + '0');
        }
        return n;
    }
    string maxValue(string n, int x) {
        if (n[0] == '-') return maxValueofNeg(n, x);
        return maxValueofPri(n, x);
    }
};