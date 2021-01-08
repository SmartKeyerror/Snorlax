
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "union_find.h"

using namespace std;

/*
 * 同样是求图中连通分量的个数，但是需要将每一个连通分量中的节点求出。
 * 
 * TODO： fix it up.
 */
class Solution {
private:
    int find(vector<int>& parents, int u) {
        while (u != parents[u]) {
            parents[u] = parents[parents[u]];
            u = parents[u];
        }
        return u;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        vector<int> parents(n);
        for (int i = 0; i < n; i++)
            parents[i] = i;

        unordered_map<string, unordered_set<int>> record;

        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (record[accounts[i][j]].size() != 0) {
                    int pu = find(parents, i);
                    int pv = find(parents, *record[accounts[i][j]].begin());
                    parents[pu] = pv;
                }
                record[accounts[i][j]].insert(i);
            }
        }

        vector<int> remains;
        for (int i = 0; i < n; i++) {
            if (parents[i] != i) {
                for (int j = 1; j < accounts[i].size(); j++)
                    accounts[i].push_back(accounts[i][j]);
            } else
                remains.push_back(i);
        }

        vector<vector<string>> result;
        for (int i = 0; i < remains.size(); i++) {
            sort(accounts[i].begin() + 1, accounts[i].end());
            result.push_back(accounts[i]);
        }
        return result;
    }
};
