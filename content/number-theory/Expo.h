/**
 * Author: Brian Grana
 * Date: 2024-10-02
 * Source: own
 * Description: Given two integers b and p,
 * computes $b^p$ under mod.
 * Time: $O(\log (p))$
 * Status: tested on https://cses.fi/problemset/task/1095/
 */
#pragma once

const ll mod = 1e9+7;
ll expo(long long b, long long p) {
	// assert(p > 0);
	ll ans = 1;
	while (p > 0) {
		if (p & 1) ans = (ans * b) % mod;
		b = (b * b) % mod;
		p >>= 1;
	}
	return ans;
}
