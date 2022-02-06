#include <bits/stdc++.h>
using namespace std;

void findLPS(string P, int m, vector<int> &lps) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < m) {
		if(P[i] == P[len]) {
			++len;
			lps[i] = len;
			++i;
		} else {
			if(len) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				++i;
			}
		}
	}
}

void kmp_search(string P, string T) {
	int n = T.length();
	int m = P.length();

	vector<int> lps(m);
	findLPS(P, m, lps);

	int i = 0;
	int j = 0;
	while(i < n) {
		if(P[j] == T[i]) {
			++i;
			++j;
		}
		if(j == m) {
			cout << "Found pattern at index = " << i - j << endl;
			j = lps[j - 1];
		} else if(i < n && P[j] != T[i]) {
			if(j) j = lps[j - 1];
			else i++;
		}
	}
}

void solve() {
	string t, p; cin >> t >> p;
	kmp_search(p, t);
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int tc = 1; cin >> tc;
	while(tc--) solve();
	return 0;
}

