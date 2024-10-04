/**
 * Author: Brian Grana
 * Date: 2024-10-02
 * Source: own
 * Description: Prime sieve that generates a boolean vector where
 * isPrime[i] = 1 if and only if i is a prime number.
 * Time: $O(N\log\log (N))$
 * Status: Tested on https://codeforces.com/gym/102953/problem/8
 */
#pragma once

vector<bool> sieve(int n) {
	vector<bool> isPrime(n+1, 1);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i * i <= n; i++) if (isPrime[i]) {
		for (int j = i * i; j <= n; j += i) isPrime[j] = 0;
	}
	return isPrime;
}
