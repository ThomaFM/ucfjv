/**
 * Author: Brian Grana
 * Date: 2025-01-10
 * Source: own
 * Description: Given an unweighted graph, finds the length
 * of the shortest path from a given source node s to every 
 * other node in the graph. Any nodes unreachable from s
 * will have distance -1.
 * Time: $O(|V| + |E|)$
 * Status: tested on https://codeforces.com/gym/104466/problem/C
 */
#pragma once

vector<int> shortestPath(vector<vector<int>>& g, int s) {
	vector<int> dist(sz(g), -1);
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while (sz(q)) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist;
}
