#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

#include <vector>

using namespace std;

class UnionFind {
private:
    int numComponents;
    vector<int> parents;

    int find(int u) {
        while (u != parents[u]) {
            parents[u] = parents[parents[u]];
            u = parents[u];
        }
        return u;
    }

public:
    UnionFind(int size) : numComponents(size) {
        parents = vector<int>(size);
        for (int i = 0; i < parents.size(); i++)
            parents[i] = i;
    }

    void unionNode(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return ;
        parents[pu] = pv;
        numComponents --;
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }

    int getCCNums() {
        return numComponents;
    }
};

#endif