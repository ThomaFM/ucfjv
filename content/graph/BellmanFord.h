/**
 * Author: Brian Grana
 * Date: 2025-09-16
 * Source: own
 * Description: Given a weighted edge list of a graph
 * and the number of nodes, determines the shortest path 
 * from a given source node to all other nodes. Allows for 
 * negative edge weights. Unreachable nodes are distance inf. 
 * Nodes reachable via a negative cycle are distance -inf.
 * Try to use Dijkstra if this TLE's.
 * Time: $O(|V||E|)$
 * Status: tested on https://cses.fi/problemset/task/1673/
 */
#pragma once

const ll inf = 1e18+5;

using edge = tuple<ll, int, int>;
vector<ll> bellmanFord(vector<edge>& ed, int n, int s) {
	vector<ll> dist(n, inf);
	dist[s] = 0;
	for (int i = 0; i < n; i++) {
		for (auto [w, u, v] : ed) {
			if (dist[u] == inf) continue;
			if (dist[u] + w < dist[v]) {
				if (i == n-1) dist[v] = -inf;
				else dist[v] = dist[u] + w;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (auto [w, u, v] : ed) {
			if (dist[u] == -inf) dist[v] = -inf;
		}
	}

	return dist;
}