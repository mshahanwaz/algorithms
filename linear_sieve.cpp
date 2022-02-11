#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> lp(N + 1);
vector<int> pr;

void solve() {
	for (int i = 2; i <= N; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	for (int i = 0; i < N; i++) {
		cout << i << ' ' << lp[i] << endl;
	}
	cout << endl;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int tc = 1; // cin >> tc;
	while(tc--) solve();
	return 0;
}

