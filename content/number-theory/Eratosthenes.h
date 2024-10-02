/**
 * Author: Brian Grana
 * Date: 2024-10-02
 * Source: own
 * Description: Prime sieve that generates a boolean vector where
 * sieve[i] = 1 if and only if the number is prime.
 * Status: Tested on https://codeforces.com/gym/102953/problem/8
 */
#pragma once

vector<bool> sieve(int n) {
	vector<bool> sv(n+1, 1);
	sv[0] = 0, sv[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (sv[i]) {
			for (int j = i * i; j <= n; j += i) sv[j] = 0;
		}
	}
	return sv;
}
