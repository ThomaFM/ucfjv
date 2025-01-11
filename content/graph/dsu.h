/**
 * Author: Thomas Meeks
 * Date: 2024-10-08
 * Source: own
 * Description: allows for quickly merging sets together
 * (join(x, y)) and finding the representive of the set a
 * specific element is in (find(x)).
 * find(x) == find(y) if/only if x and y are in the same set
 * used to represent connected components in undirected graphs 
 * Time: $O(N)$ Memory, amortized $O(\alpha(N))$ for find/join
 * , where $\alpha(N) < 4$ for all feasible input sizes
 * Status: Tested on codeforces edu dsu problems
 */
#pragma once

struct dsu {
    vector<int> par, siz;
    dsu(int n) {
        siz = par = vector<int>(n, 1);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int a) {
        if (par[a] != a) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        siz[u] += siz[v];
        par[v] = u; 
        return true;
    }
};
