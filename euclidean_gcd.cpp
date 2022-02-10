#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(!b) return a;
	else return gcd(b, a % b);
}

void solve() {
	int a, b; cin >> a >> b;
	cout << gcd(a, b) << endl;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

