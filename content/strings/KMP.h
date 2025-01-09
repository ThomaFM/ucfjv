/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: pi[x] computes the length of the longest 
 * prefix of s that ends at x, other than s[0...x] itself
 * Ex: (abacaba -> 0010123)
 * match finds the starting indexes for all occurrences 
 * of a specific pattern in s (overlaps allowed)
 * Time: O(n)
 * Status: Tested on https://cses.fi/problemset/task/1753/
 */
#pragma once

vector<int> kmp(const string& s) {
	vector<int> pi(sz(s));
	for (int i = 1; i < sz(s); i++) {
		pi[i] = pi[i-1];
		while (pi[i] && s[i] != s[pi[i]]) pi[i] = pi[pi[i]-1];
		if (s[i] == s[pi[i]]) pi[i]++;
	}
	return pi;
}

vector<int> match(const string& s, const string& pat) {
	vector<int> p = kmp(pat + '\0' + s), res;
	for (int i = sz(p)-sz(s); i < sz(p); i++)
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}
