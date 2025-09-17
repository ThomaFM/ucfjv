/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Description: Flow algorithm with complexity $O(E^2\log U)$ where $U = \max |\text{cap}|$.
 * Usage: If the maximum capacity is larger than $2^{30}$, update max_cap to reflect that.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */
#pragma once

struct FFA {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<vector<Edge>> adj;
	vector<bool> seen;
	const ll max_cap = 1LL << 30;
	FFA(int n) : adj(n), seen(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, adj[b].size(), c, c});
		adj[b].push_back({a, adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int cur, int t, ll f, ll lim) {
		if (cur == t || !f) return f;
		for (Edge &e: adj[cur]) {
			if(e.c < lim) continue;
			ll nxt_f = dfs(e.to, t, min(f, e.c), lim);
			if (nxt_f != 0) {
				e.c -= nxt_f;
				adj[e.to][e.rev].c += nxt_f;
				return nxt_f;
			}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0, cur_f;
		for(int lim = max_cap; lim > 0; lim /= 2) {
			do {
				cur_f = dfs(s, t, max_cap, lim);
				flow += cur_f;
			} while(cur_f > 0);
		}
		return flow;
	}
	bool leftOfMinCut(int a) { return seen[a]; }
};
