
#include <vector>

using namespace std;


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int A = rec1[0], B = rec1[1], C = rec1[2], D = rec1[3];
        int E = rec2[0], F = rec2[1], G = rec2[2], H = rec2[3];

        // [-1,0,1,1] [0,-1,0,1]，还有这种数据?? 直线是矩形吗??
        long long area1 = (long long)abs(A - C) * (long long)abs(B - D);
        long long area2 = (long long)abs(E - G) * (long long)abs(F - H);

        if (B >= H || E >= C || A >= G || F >= D || area1 == 0 || area2 == 0)
            return false;
        return true;
    }
};