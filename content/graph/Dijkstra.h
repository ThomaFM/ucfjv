/**
 * Author: Brian Grana
 * Date: 2025-01-09
 * Source: own
 * Description: Given a weighted graph, finds the shortest
 * distance from a given source node s to every single other
 * node on the graph. Any nodes unreachable from s will
 * have a distance of infinity.
 * Time: $O(|V| + |E|log|V|)$
 * Status: tested on https://cses.fi/problemset/task/1195/
 */
#pragma once

const ll inf = 1e18+5;

vector<ll> dijkstra(vector<vector<pair<int, ll>>>& g, int s) {
	vector<ll> dist(sz(g), inf);
	priority_queue<pair<ll, int>, 
		vector<pair<ll, int>>, greater<>> pq;
	dist[s] = 0;
	pq.emplace(0, s);
	while (sz(pq)) {
		auto [du, u] = pq.top();
		pq.pop();
		if (du > dist[u]) continue;
		for (auto [v, w] : g[u]) {
			if (du + w < dist[v]) {
				dist[v] = du + w;
				pq.emplace(du + w, v);
			}
		}
	}
	return dist;
}
