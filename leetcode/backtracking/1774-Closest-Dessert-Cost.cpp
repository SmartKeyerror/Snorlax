
#include <vector>
#include <cmath>

using namespace std;


class Solution {

    int target;

    int closest(int a,int b){ 
        if(a==0)
            return b;
        if(b==0)
            return a;
        if(abs(target-a)==abs(target-b))
            return a < b ? a : b;
        return abs(target - a) < abs(target - b) ? a : b;
    }

    int dfs(vector<int>& toppingCosts, int index, int current) {
        if (index >= toppingCosts.size()) return current;

        // 什么都不选
        int a = dfs(toppingCosts, index + 1, current);

        // 选择当前配料
        int b = dfs(toppingCosts, index + 1, current + toppingCosts[index]);

        // 选择当前全部配料
        int c = dfs(toppingCosts, index + 1, current + (toppingCosts[index] * 2));

        return closest(a, closest(b, c));
    }

public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int t) {
        target = t;

        int result = 0;
        for (int i = 0; i < baseCosts.size(); i++) {
            result = closest(dfs(toppingCosts, 0, baseCosts[i]), result);
        }

        return result;
    }
};