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
	Node *l = 0, *r = 0;
	int lo, hi;
	ll val = 0;
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo) / 2;
			l = new Node(lo, mid), r = new Node(mid, hi);
		}
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return LLONG_MAX;
		if (L <= lo && hi <= R) return val;
		return comb(l->query(L, R), r->query(L, R));
	}
	void add(int idx, int v) {
		if (lo + 1 == hi) {
			val += v;
			return;
		}
		int mid = lo + (hi - lo) / 2;
		(mid <= idx ? r : l)->add(idx, v);
		val = comb(l->val, r->val);
	}
	ll comb(ll a, ll b) { return min(a, b); }
};
