/**
 * Author: Sachin Sivakumar
 * Date: 2024-10-09
 * License: CC0
 * Source: Inspired by KACTL
 * Description: Segment tree supporting Range Minimum Queries and Point Add Queries
 * Time: O(\log N)
 * Status: tested on https://cses.fi/problemset/task/1649
 */
#pragma once

struct Node {
	Node *left = 0, *right = 0;
	int lo, hi;
	ll val = 0; // initial value of segment
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo) / 2;
			left = new Node(lo, mid), right = new Node(mid, hi);
		}
	}
	// queries min on [L, R) range
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return LLONG_MAX; // idempotent value
		if (L <= lo && hi <= R) return val;
		return comb(left->query(L, R), right->query(L, R));
	}
	void add(int idx, int v) {
		if (lo + 1 == hi) {
			val += v;
			return;
		}
		int mid = lo + (hi - lo) / 2;
		(mid <= idx ? right : left)->add(idx, v);
		val = comb(left->val, right->val);
	}
	ll comb(ll a, ll b) { return min(a, b); }
};
