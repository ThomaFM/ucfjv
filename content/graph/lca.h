/**
 * Author: Thomas Meeks
 * Date: 2024-10-08
 * Source: own
 * Description: Given a tree creates structure allowing for 
 * O(log(n)) Lowest Common Ancestor queries between arbitary nodes 
 * (default root = 0)
 * Time: O(Nlog(N)) Precomp, O(log(N)) query
 * Status: Tested on https://cses.fi/problemset/task/1652
 *              https://open.kattis.com/problems/tourists
 */
struct LCA{
	vector<int> dep; 
	vector<vector<int>> jmp, g;
	LCA(vector<vector<int>> &g, int root = 0): 
		dep(sz(g)), jmp(__lg(sz(g))+1, vector<int>(sz(g))), g(g) {
		dfs(root, root);
		for(int lvl = 1; lvl < sz(jmp); lvl++)
			for(int u = 0; u < sz(g); u++)
				jmp[lvl][u] = jmp[lvl-1][jmp[lvl-1][u]];
	}
	void dfs(int u, int p){
		jmp[0][u] = p; 
		for(auto v : g[u]) if(v != p) {
			dep[v] = dep[u]+1;
			dfs(v, u);
		}
	}    
	int kth_ancestor(int u, int k){
		for(int i = 0; i < sz(jmp); i++)
			if(k & (1<<i)) u = jmp[i][u];
		return u;
	}
	int lca(int u, int v){
		if(dep[u] > dep[v]) swap(u, v); //v is now deeper
		v = kth_ancestor(v, dep[v]-dep[u]); 
		if(u == v) return u;
		for(int i = sz(jmp)-1; i >= 0 ; i--){
			if(jmp[i][u] != jmp[i][v]){
				u = jmp[i][u];
				v = jmp[i][v];
			}
		}
		return jmp[0][u];
	}
	int dist(int u, int v){
		return dep[u] + dep[v] - 2*dep[lca(u, v)];
	}
};
