/**
 * Author: Brian Grana
 * Date: 2024-09-26
 * Source: own
 * Description: Given an undirected graph, finds a way to 
 * color the nodes of the graph such that every edge connects.
 * nodes of different colors. Each node is colored 0 or 1.
 * Returns an empty vector if there is no valid two-coloring.
 * Time: $O(|V|+|E|)$
 * Status: tested on https://cses.fi/problemset/task/1668
 */
#pragma once

vector<int> TwoColor(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int> col(n, -1);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (col[i] == -1) q.push(i), col[i] = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto v : graph[u]) {
				if (col[v] == col[u]) return {};
				if (col[v] == -1) {
					col[v] = col[u]^1; // ^1 inverts color
					q.push(v);
				}
			}
		}
	}
	return col;
}