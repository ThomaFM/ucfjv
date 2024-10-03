/**
 * Author: Brian Grana
 * Date: 2024-09-30
 * Source: own
 * Description: Calculates sub-rectangle sums in O(1) time.
 * Query function gets subgrid sum on any elements with row
 * [r1, r2) and column [c1, c2).
 * Time: O(NM + Q)
 * Status: Tested on https://cses.fi/problemset/task/1652
 */
#pragma once

struct PS2D {
	vector<vector<ll>> ps;
	int n, m;
	PS2D(vector<vector<ll>>& a) {
		n = size(a), m = size(a[0]);
		ps = vector(n+1, vector<ll>(m+1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ps[i+1][j+1] = a[i][j] + ps[i][j+1]
				 + ps[i+1][j] - ps[i][j];
			}
		}
	}
	ll query(int r1, int c1, int r2, int c2) {
		return ps[r2][c2] - ps[r1][c2] - ps[r2][c1] + ps[r1][c1];
	}
};
