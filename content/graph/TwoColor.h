/**
 * Author: Brian Grana
 * Date: 2024-09-26
 * Source: own
 * Description: Given a graph, finds a way to color the nodes of the graph such that 
 * No two nodes that share an edge are the same color. Each node will be either colored 0 or 1.
 * Returns an empty vector if there is no valid two-coloring
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
                if (col[v] == -1) {
                    col[v] = col[u]^1; // sets color to opposite of current
                    q.push(v);
                } else if (col[v] == col[u]) return {};
            }
        }
    }
    return col;
}