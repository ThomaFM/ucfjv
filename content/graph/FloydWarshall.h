/**
 * Author: Brian Grana
 * Date: 2024-01-10
 * Source: own
 * Description: Given a weighted adjacency matrix, returns
 * a new weighted adjacency matrix M such that M[i][j] is
 * equivalent to the weight of the shortest path starting
 * at node i and ending at node j. Set any edges that don't
 * exist to infinity.
 * Time: $O(|V|^3)$
 * Status: tested on https://cses.fi/problemset/task/1672
 */
#pragma once

const ll inf = 1e18+5;

vector<vector<ll>> floydWarshall(vector<vector<ll>> M) {
	for (int i = 0; i < sz(M); i++) M[i][i] = 0;
	for (int p = 0; p < sz(M); p++) {
		for (int s = 0; s < sz(M); s++) {
			for (int d = 0; d < sz(M); d++) {
				M[s][d] = min(M[s][d], M[s][p] + M[p][d]);
			}
		}
	}
	return M;
}
