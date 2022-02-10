#include <bits/stdc++.h>
using namespace std;

int ext_gcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void solve() {
	int a, b, x, y; cin >> a >> b;
	cout << ext_gcd(a, b, x, y) << endl;
	cout << x << ' ' << y << endl;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

