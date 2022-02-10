#include <bits/stdc++.h>
using namespace std;

// iterative binpow(a,b) implementation
long long binpow(long long a, long long b) {
	long long res = 1;
	while(b > 0) {
		if(b & 1) {
			res *= a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

long long binpow(long long a, long long b) {
	if(b == 0) return 1;
	long long res = binpow(a, b / 2);
	if(b & 1) return res * res * a;
	else return res * res;
}

void solve() {
	int a = 3, b = 13;
	cout << binpow(a, b) << endl;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

