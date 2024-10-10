/**
 * Author: Sachin Sivakumar
 * Date: 2024-10-09
 * License: CC0
 * Source: Inspired by KACTL
 * Description: Segment tree supporting Range Minimum Queries
 * (returns minimum value on the inclusive-exclusive range [L,R)
 * in the tree) and Point Add Queries (add v to a specific index)
 * Time: O(\lg N) for both operations
 * Status: tested on https://cses.fi/problemset/task/1649
 */
#pragma once

struct Node {
	Node *left = 0, *right = 0;
	int lo, hi;
	ll val = 0; // initial value of segment
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 == hi) return;
		int mid = (lo + hi) / 2;
		left = new Node(lo, mid), right = new Node(mid, hi);
	}
	// queries min on [L, R) range
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return LLONG_MAX; // idempotent value
		if (L <= lo && hi <= R) return val;
		return merge(left->query(L, R), right->query(L, R));
	}
	void add(int idx, int v) {
		if (lo + 1 == hi) {
			val += v;
			return;
		}
		int mid = (lo + hi) / 2;
		if (mid <= idx) right->add(idx, v);
		else left->add(idx, v);
		val = merge(left->val, right->val);
	}
	ll merge(ll a, ll b) { return min(a, b); }
};
