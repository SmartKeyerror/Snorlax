
#include <vector>
#include <map>

using namespace std;

/*
 * 凑对子问题，arr.size() 规定为偶数，所以我们只需要在 arr 中凑出 arr.size()/2 这么多个对子就可以了。
 */
class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        map<int, int, greater<int>> m;
        for(const auto & i : a) m[i]++;

        for(const auto & [x ,y] : m)
            if(y) {
                int z = x>0 ? x/2 : 2*x;
                if(y>0 and (x<0 or x%2==0) and m.find(z)!=m.end()) 
                    m[z] -= y;
                else
                    return false;
            }

        return true;
    }
};