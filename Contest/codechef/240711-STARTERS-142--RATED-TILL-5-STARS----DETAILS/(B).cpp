#include <bits/stdc++.h>
#define y second
#define x first

using namespace std;
using pii = pair<int, int>;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the smallest prime number greater than x
int smallestPrimeGreaterThanX(int x) {
    int candidate = x;
    while (!isPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
#endif

	int t; scanf("%d", &t);
	while(t--) {
		int x; scanf("%d", &x);
		x = smallestPrimeGreaterThanX(x);
		printf("%lld\n", (long long)x * smallestPrimeGreaterThanX(x + 1));
	}
}
