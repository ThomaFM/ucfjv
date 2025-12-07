/**
 * Author: Brian Grana
 * Date: 2025-12-07
 * Source: Own
 * Description: Set that stores strings.
 * Allows for queries pretaining to prefixes of strings.
 * Time: $O(\Sigma \left| s \right|)$
 * Status: 
 */
#pragma once

struct node {
	int p_count, w_count;
	map<char, int> nxt;
	node(): p_count(0), w_count(0) {}
};

struct Trie {
	vector<node> t;
	Trie(): t(1) {}
	void insert(string& s) {
		int cn = 0;
		t[0].p_count++;
		for (int i = 0; i < sz(s); i++) {
			if (!t[cn].nxt.count(s[i])) {
				t[cn].nxt[s[i]] = sz(t);
				t.emplace_back();
			}
			cn = t[cn].nxt[s[i]];
			t[cn].p_count++;
		}
		t[cn].w_count++;
	}
	int query_word(string& s) {
		int cn = 0;
		for (int i = 0; i < sz(s); i++) {
			if (!t[cn].nxt.count(s[i])) return 0;
			cn = t[cn].nxt[s[i]];
		}

		return t[cn].w_count;
	}
	int query_prefix(string& s) {
		int cn = 0;
		for (int i = 0; i < sz(s); i++) {
			if (!t[cn].nxt.count(s[i])) return 0;
			cn = t[cn].nxt[s[i]];
		}

		return t[cn].p_count;
	}
};
