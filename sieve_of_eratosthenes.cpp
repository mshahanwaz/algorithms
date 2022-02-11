#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i * i <= n; i++) {
		if(is_prime[i]) {
			for(int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for(int i = 0; i < n + 1; i++) {
		if(is_prime[i]) cout << i << endl;
	}
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

